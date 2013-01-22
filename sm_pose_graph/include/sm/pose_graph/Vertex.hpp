#ifndef SM_POSE_GRAPH_VERTEX_HPP
#define SM_POSE_GRAPH_VERTEX_HPP

#include <boost/cstdint.hpp>
#include <sm/Id.hpp>
#include <sm/boost/serialization.hpp>



namespace sm { 
    namespace pose_graph {
        SM_DEFINE_ID(VertexId);
    }

}

SM_DEFINE_ID_HASH(sm::pose_graph::VertexId);

namespace sm { 
    namespace pose_graph {

        ///
        /// @class Vertex
        /// @brief A class representing a vertex in a pose graph
        ///
        /// Vertices in a pose graph represent coordinate frames. 
        /// Each vertex has a metadata container that allows arbitrary
        /// data to be stored at the vertex.
        ///
        class Vertex
        {
        public:

            /// 
            /// Default constructor. The id is set to zero.
            ///
            Vertex();
      
            /// 
            /// Constructor that initialized the id.
            ///
            /// @param id The Vertex's unique id.
            /// @param stamp the Vertex time stamp.
            ///
            Vertex(VertexId id);

            ///
            /// Destructor. 
            ///
            virtual ~Vertex();

            /// 
            /// A mutator to set the vertex's unique id. This should be used with
            /// caution.
            ///
            /// @param id The vertex's unique id. 
            ///
            void setId(VertexId id);

            /// 
            /// An accessor to the get vertex's unique id (const version)
            ///
            /// @return The unique id identifying the vertex.
            ///
            VertexId id() const;

            enum {CLASS_SERIALIZATION_VERSION = 0};
            BOOST_SERIALIZATION_SPLIT_MEMBER();

            /// 
            /// Serialize the Vertex to a boost::serialization archive.
            ///
            /// @param ar The archive
            /// @param version The archive file version number.
            ///
            template<class Archive>
            void save(Archive & ar, const unsigned int version) const;

            template<class Archive>
            void load(Archive & ar, const unsigned int version);

            bool isBinaryEqual(const Vertex & rhs) const;

        private:

            /// The vertex's unique id.
            VertexId _id;

        };

        template<class Archive>
        void Vertex::save(Archive & ar, const unsigned int version) const
        {ar << BOOST_SERIALIZATION_NVP(_id);
        }

        template<class Archive>
        void Vertex::load(Archive & ar, const unsigned int version)
        {
            ar >> BOOST_SERIALIZATION_NVP(_id);
        }

  
    }
} // namespace sm::pose_graph


SM_BOOST_CLASS_VERSION(sm::pose_graph::Vertex);


#endif
