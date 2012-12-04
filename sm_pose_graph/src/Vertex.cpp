#include <sm/pose_graph/Vertex.hpp>

namespace sm { namespace pose_graph {


    Vertex::Vertex()
    {

    }

    Vertex::~Vertex()
    {

    }


    Vertex::Vertex(VertexId id) :
      _id(id)
    {

    }


    void Vertex::setId(VertexId id)
    {
      _id = id;
    }


    VertexId Vertex::id() const
    {
      return _id;
    }

        
        bool Vertex::isBinaryEqual(const Vertex & rhs) const
        {
            return _id == rhs._id;
        }

  }} // namespace sm::pose_graph
