#ifndef SM_POSE_GRAPH_VERTEX_HPP
#define SM_POSE_GRAPH_VERTEX_HPP

#include <boost/cstdint.hpp>
#include <sm/Id.hpp>


namespace sm { namespace pose_graph {
    
    SM_DEFINE_ID(VertexId);

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

      /// 
      /// Serialize the Vertex to a boost::serialization archive.
      ///
      /// @param ar The archive
      /// @param version The archive file version number.
      ///
      template<class Archive>
      void serialize(Archive & ar, const unsigned int version);

    private:

      /// The vertex's unique id.
      VertexId id_;

    };

    template<class Archive>
    void Vertex::serialize(Archive & ar, const unsigned int version)
    {
      ar & id_;
    }
  
  }} // namespace sm::pose_graph

#endif
