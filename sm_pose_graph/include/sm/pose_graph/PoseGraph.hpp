/*
 * Adapted from the Willow Garage pose_graph package by Paul Furgale on October 22, 2010.
 * 
 * Original version:
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef SM_POSE_GRAPH_GRAPH_HPP
#define SM_POSE_GRAPH_GRAPH_HPP

#include <sm/Id.hpp>
//#define BOOST_NO_HASH
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/subgraph.hpp>
#include <boost/graph/graph_traits.hpp>
#include <boost/graph/adj_list_serialize.hpp>
#include <boost/serialization/map.hpp>
#include <boost/filesystem.hpp>
#include <gtest/gtest_prod.h>
#include <sm/eigen/serialization.hpp>
#include <boost/unordered_map.hpp>
#include "Edge.hpp"
#include "Vertex.hpp"
#include <sm/boost/serialization.hpp>


namespace sm { 

    namespace pose_graph {
    

        class PoseGraph
        {
        public:

            // Boost graph documentation:
            // http://www.boost.org/doc/libs/1_43_0/libs/graph/doc/adjacency_list.html
            // adjacency_list<OutEdgeList, VertexList, 
            //                Directed, VertexProperties, EdgeProperties,
            //                GraphProperties, EdgeList>
            // The selections for OutEdgeList and VertexList change the memory requirements 
            // for the graph and computational complexity for different operations. 
            // See: http://www.boost.org/doc/libs/1_43_0/libs/graph/doc/using_adjacency_list.htm
            typedef boost::adjacency_list<boost::vecS, boost::vecS, 
                                          boost::undirectedS, Vertex, Edge> graph_t;
            typedef boost::subgraph<graph_t> subgraph_t;
            typedef boost::graph_traits<graph_t> graph_traits;
            // http://www.boost.org/doc/libs/1_38_0/libs/graph/doc/graph_traits.html
            typedef boost::graph_traits<graph_t>::edge_descriptor graph_edge_t;
            typedef boost::graph_traits<graph_t>::vertex_descriptor graph_vertex_t;    
            typedef boost::graph_traits<graph_t>::out_edge_iterator out_edge_iterator;    
            typedef boost::graph_traits<graph_t>::edge_iterator edge_iterator;    
            typedef boost::graph_traits<graph_t>::vertex_iterator vertex_iterator;    

            typedef std::pair<VertexId, VertexId> IncidentVertices;
            //typedef std::map<VertexId, PoseGraph::graph_vertex_t> VertexMap;
            typedef boost::unordered_map<VertexId, PoseGraph::graph_vertex_t> VertexMap;
            typedef boost::unordered_map<EdgeId, PoseGraph::graph_edge_t> EdgeMap;
            typedef boost::unordered_set<EdgeId> EdgeSet;
            typedef boost::unordered_set<VertexId> VertexSet;


            /****************************************
             * Construction
             ****************************************/

            /// Create empty graph
            PoseGraph ();

        private:
            /// copy constructor
            //PoseGraph (const PoseGraph& g);
      
            /// assignment operator
            //virtual PoseGraph& operator= (const PoseGraph& g);
        public:

            /// Destructor
            virtual ~PoseGraph ();

            /****************************************
             * Basic modification
             ****************************************/
  
            /// Add a new node, and return its id
            VertexId addVertex ();
      
            /// \brief Add a new node with a given id
            /// \throw DuplicateVertexIdException if already exists
            void addVertex (VertexId id);

            /// Add a new edge and return its id. This function also deals
            /// with the subgraph ids. These are the rules: Merging of
            /// disconnected subgraphs is currently not supported.  This
            /// should be possible but someone who needs this will have to
            /// sit down and have a think about how to do this so currently,
            /// we just detect if this edge merges two disconnected
            /// subgraphs and then throw an exception if they do.
            EdgeId addEdge (VertexId to, VertexId from, const transformation_t & T_to_from);
      
            ///
            /// \brief Add a new edge with the given id 
            ///
            /// \throw DuplicateEdgeIdException 
            ///
            /// if already exists This function also deals with the subgraph
            /// ids. These are the rules: Merging of disconnected subgraphs
            /// is currently not supported.  This should be possible but
            /// someone who needs this will have to sit down and have a
            /// think about how to do this so currently, we just detect if
            /// this edge merges two disconnected subgraphs and then throw
            /// an exception if they do.
            ///
            void addEdge (EdgeId id, VertexId to, VertexId from, const transformation_t& T_to_from);
      
            /// \brief Clear the current graph
            void clearGraph();

            /****************************************
             * Basic const ops
             ****************************************/

            /// \brief Get set of node ids
            VertexSet allVertices() const;

            /// \brief Get set of edge ids
            EdgeSet allEdges() const;

            /// \brief Get set of edges incident to a node
            /// \note Returned value may change; make a copy if necessary
            EdgeSet incidentEdges (VertexId n) const;

            /// \brief Get pair of nodes adjacent to this edge, in order (to, from)
            /// \throw UnknownEdgeIdException
            std::pair<VertexId, VertexId> incidentVertices (EdgeId e) const;

            /// \brief Get transformation attached to this edge
            /// \note Returned value may change; make a copy if necessary
            const transformation_t & getTransformation (EdgeId e) const;

            /****************************************
             * Helper functionality
             ****************************************/

            //std::set<VertexId> bfsNeighbours(VertexId rootVertex, int depth);
      
            /** 
             * Writes the structure of the graph to graphviz. To create a pdf
             * version of the graph, use
             *
             * dot -Tpdf graph.dot -o graph.pdf
             * 
             * @param dotFile The output filename.
             */
            void writeGraphViz(boost::filesystem::path const & dotFile) const;


            // Returns T_to_from
            // These guys only work if there is a single edge between to and from
            Eigen::Matrix4d getEdgeTransformationMatrix(VertexId to, VertexId from) const;
            Eigen::Matrix4d getEdgeTransformationMatrix(VertexId to, graph_vertex_t from) const;
      
            // returns T_to_from;
            // These guys only work if there is a single edge between to and from
            transformation_t getEdgeTransformation(VertexId to, VertexId from) const;
            transformation_t getEdgeTransformation(VertexId to, graph_vertex_t from) const;
            transformation_t getEdgeTransformation(graph_vertex_t to, VertexId from) const;

            // Returns...T_to_from?
            transformation_t breadthFirstSearch(VertexId toId, VertexId fromId, std::vector<VertexId> * outPath = NULL) const;

            // returns T_to_from;
            Eigen::Matrix4d getTransformationMatrix(VertexId to, VertexId from) const;
            Eigen::Matrix4d getTransformationMatrix(graph_vertex_t to, graph_vertex_t from) const;


      
            // returns T_to_from;
            transformation_t getTransformation(VertexId to, VertexId from) const;
            transformation_t getTransformation(graph_vertex_t to, graph_vertex_t from) const;

            const Edge & getEdge(EdgeId edgeId) const;
            const Edge & getEdge(VertexId v1, VertexId v2) const;
            const Vertex & getVertex(VertexId vertexId) const;


            void updateEdgeTransformation(EdgeId edgeId, const transformation_t & T_to_from); 

            bool pathExists(const std::vector<boost::uint64_t> & path) const;
            bool pathExists(const std::vector<VertexId> & path) const;

            /****************************************
             * const utilities
             ****************************************/

            bool vertexExists (VertexId n) const;
            bool edgeExists (EdgeId e) const;
            bool edgeExists(VertexId v1, VertexId v2) const;
      
            /****************************************
             * Serialization convenience
             ****************************************/
            enum {CLASS_SERIALIZATION_VERSION = 0};

            /// \brief Save the graph to disk.
            void save(const boost::filesystem::path & graphFileName) const;
            /// \brief Load the graph from disk.
            void load(const boost::filesystem::path & graphFileName);

            EdgeId nextEdgeId();
            VertexId nextVertexId();

            bool isBinaryEqual(const PoseGraph & rhs);

        private:
      
            // Provide private member access to some of the test cases.
            //FRIEND_TEST(PoseGraphTestSuite, testEdges);
      
            //FRIEND_TEST(PoseGraphSerializationSuite,poseGraphSerializationTest);
            //FRIEND_TEST(PoseGraphSerializationSuite,poseGraphSerializationTest);      

            /****************************************
             * Ops on underlying graph
             ****************************************/

            /// \brief Return (a const reference to) the underlying Boost graph.
            ///
            /// To get convert ids into edge/vertex handles for use with the returned object,
            /// use idVertex and idEdge 
            const graph_t & graph () const;
            graph_t & graph ();

            /// \brief Get the node handle given an id
            /// \throw UnknownVertexIdException
            graph_vertex_t idVertex (VertexId n) const;

            /// \brief Get the edge handle given an id
            graph_edge_t idEdge (EdgeId e) const;

            /****************************************
             * Development
             ****************************************/

            /** 
             * Gets the edge from one vertex to another. Throws an exception if this edge doesn't exist
             * 
             * @param from The Vertex whose edges will be searched.
             * @param to   The Vertex we are searching an edge to
             * 
             * @return     Returns a pointer to the edge and a bool that says weather or not the transformation matrix
             *             has to be inverted to get T_to_from from the edge.
             */
            std::pair<const Edge *, bool> getEdgeInternal(VertexId to, VertexId from) const;
            std::pair<graph_edge_t, bool> getEdgeInternal(VertexId to, graph_vertex_t from) const;

            
        

        private:
            template<typename T>
            bool pathExistsInternal(const std::vector<T> & path) const;
            //template<typename T>
            //LocalizationChain localizationChainFromPathInternal(const std::vector<T> & path, const std::string & frameId) const;



            /****************************************
             * Boost Serialization
             ****************************************/
            friend class boost::serialization::access;

            template<class Archive>
            void save(Archive & ar, const unsigned int version) const;

            template<class Archive>
            void load(Archive & ar, const unsigned int version);
      
            BOOST_SERIALIZATION_SPLIT_MEMBER();

            /****************************************
             * Modifying utilities
             ****************************************/
            //void initializeFrom (const PoseGraph& other);
  
            VertexId _nextVertexId;
            EdgeId _nextEdgeId;

            VertexMap _vertexMap;
            EdgeMap _edgeMap;
            graph_t _graph;

        };

        /************************************************************
         * Other useful typedefs
         ***********************************************************/

        //typedef std::map<VertexId, geometry_msgs::Pose> VertexPoseMap;
        

        template<class Archive>
        void PoseGraph::save(Archive & ar, const unsigned int version) const
        {
            ar << BOOST_SERIALIZATION_NVP(_nextVertexId);
            ar << BOOST_SERIALIZATION_NVP(_nextEdgeId);
      
            // PTF: The vertex and edge maps are just for convenience.
            // Plus, this doesn't actually work. :P
            // Best guess is that it doesn't work because the maps are
            // from Id type to void * and boost::serialization (rightly)
            // shys away from accepting a void * (i.e. just serializing it
            // as an int).
            // In any case, they can be reconstituted from the graph. See the
            // implementaion of load() below.
            //ar << BOOST_SERIALIZATION_NVP(_vertex_map);
            //ar << BOOST_SERIALIZATION_NVP(_edge_map);

            ar << BOOST_SERIALIZATION_NVP(_graph);
        }
    

        template<class Archive>
        void PoseGraph::load(Archive & ar, const unsigned int version)
        {
            SM_ASSERT_LE(std::runtime_error, version, (unsigned int)CLASS_SERIALIZATION_VERSION, "Unsupported serialization version");

            _graph.clear();
            ar >> BOOST_SERIALIZATION_NVP(_nextVertexId);
            ar >> BOOST_SERIALIZATION_NVP(_nextEdgeId); 
            ar >> BOOST_SERIALIZATION_NVP(_graph);
      

            // Now restore the vertex and edge maps.
            // See the implementation of save() above to see why this is necessary.
            // First the vertex map
            _vertexMap.clear();
            boost::graph_traits<graph_t>::vertex_iterator v, vend;
            boost::tie(v,vend) = vertices(_graph);
            for( ; v != vend; v++)
            {
                // *v is a vertex descriptor.
                // calling _graph[*v] returns the object stored at the vertex.
                _vertexMap[_graph[*v].id()] = *v;
            }

            // A similar process holds for the edge map
            _edgeMap.clear();
            boost::graph_traits<graph_t>::edge_iterator e, eend;
            boost::tie(e,eend) = edges(_graph);
            for( ; e != eend; e++)
            {
                // *e is an edge descriptor.
                // calling _graph[*e] returns the object stored at the edge.
                _edgeMap[_graph[*e].id()] = *e;
            }

        }

    }} // sm::pose_graph

SM_BOOST_CLASS_VERSION(sm::pose_graph::PoseGraph);


#endif // SM_POSE_GRAPH_GRAPH_HPP
