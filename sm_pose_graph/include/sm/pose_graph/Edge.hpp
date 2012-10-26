#ifndef SM_POSE_GRAPH_EDGE_HPP
#define SM_POSE_GRAPH_EDGE_HPP

#include <sm/Id.hpp>
#include "Vertex.hpp"
#include "Transformation.hpp"
#include <boost/shared_ptr.hpp>

namespace sm { namespace pose_graph {
    SM_DEFINE_ID(EdgeId);

    ///
    /// @class Edge
    /// @brief A class representing a edge in a pose graph
    ///
    /// Vertices in a pose graph represent coordinate frames.
    /// Edges represent transformations between coordinate frames.
    /// Each edge is directed in the sense that it stores a directed
    /// affine transformation. The edge stores the unique keys (to() and from())of the
    /// coordinate frames the transformation is defined with respect to. 
    /// The function T_to_from() returns the affine transformation matrix that
    /// transforms points in the "from" frame to points in the "to" frame:
    /// 
    /// \f$ \mathbf p_{\text{to}} = \mathbf T_{\text{to},\text{from}} \mathbf p_{\text{from}} \f$
    ///
    /// Each edge has a metadata container that allows arbitrary
    /// data to be stored at the edge.
    ///
    class Edge
    {
    public:
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

      /// 
      /// Default constructor. The id is set to zero.
      ///
      Edge();
      
      /// 
      /// Constructor to build a fully initialized edge.
      ///
      /// @param id       The edge id
      /// @param to        The vertex id at the head of the edge
      /// @param from      The vertex id at the tail of the edge
      /// @param T_to_from The uncertain transformation associated with the edge.
      ///
      Edge(EdgeId id, VertexId to, VertexId from, transformation_t const & T_to_from);

      ///
      /// Destructor. 
      ///
      virtual ~Edge();

      /** 
       * Define the copy constructor
       * 
       * @param rhs The edge to copy
       */
      Edge(const Edge & rhs);

      /** 
       * Define the assignment operator
       * 
       * @param rhs The edge to copy
       * 
       * @return *this
       */
      Edge & operator=(const Edge & rhs);

      /// 
      /// A mutator to set the edge's unique id. This should be used with
      /// caution (or not used) \todo: remove?
      ///
      /// @param id The unique id identifying the edge
      ///
      void setId(EdgeId id);

      /// 
      /// An accessor to the get edge's unique id (const version)
      ///
      /// @return The unique id identifying the edge.
      ///
      EdgeId id() const;

      /// 
      ///
      /// @return the unique id of the "to" end of the edge 
      ///
      VertexId to() const;

      /// 
      ///
      /// @return The unique id of the "from" end of the edge 
      ///
      VertexId from() const;

      /// 
      /// 
      /// @return The transformation stored in the edge
      ///
      const transformation_t & T_to_from() const;
      
      /// 
      /// 
      /// @return The transformation stored in the edge
      ///
      transformation_t & T_to_from();

      /** 
       * Set the edge transformation matrix
       * 
       * @param T_to_from the new transformation matrix.
       */
      void set_T_to_from(const transformation_t & T_to_from);

      
      /// 
      /// Serialize the Edge to a boost::serialization archive.
      ///
      /// @param ar The archive
      /// @param version The archive file version number.
      ///
      template<class Archive>
      void serialize(Archive & ar, const unsigned int version);

    private:

      /// The edge's unique id.
      EdgeId id_;

      /// The underlying transformation
      /// We had some failures to do with Eigen aligned pointers.
      /// Making this a shared_ptr<> seems like it should fix the errors.
      boost::shared_ptr<transformation_t> T_to_from_;

      /// The "to" coordinate frame id.
      VertexId to_;
      
      /// The "from" coordinate frame id.
      VertexId from_;

      
    };

    template<class Archive>
    void Edge::serialize(Archive & ar, const unsigned int version)
    {
      ar & id_;
      ar & *T_to_from_;
      ar & to_;
      ar & from_;
    }

  }} // namespace sm::pose_graph

#endif
