#include <sm/pose_graph/Vertex.hpp>

namespace sm { namespace pose_graph {


    Vertex::Vertex()
    {

    }

    Vertex::~Vertex()
    {

    }


    Vertex::Vertex(VertexId id) :
      id_(id)
    {

    }


    void Vertex::setId(VertexId id)
    {
      id_ = id;
    }


    VertexId Vertex::id() const
    {
      return id_;
    }



  }} // namespace sm::pose_graph
