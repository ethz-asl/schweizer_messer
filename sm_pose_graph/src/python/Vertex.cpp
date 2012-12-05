#include <sm/pose_graph/Vertex.hpp>
#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/Id.hpp>
#include <sm/python/Id.hpp>

using namespace sm::pose_graph;
using namespace boost::python;


void export_Vertex()
{
    sm::python::Id_python_converter<VertexId>::register_converter();

    class_<Vertex>("Vertex",init<>())
        .def(init<VertexId>("Vertex(id)"))
        .def("setId",&Vertex::setId)
        .def("id",&Vertex::id)
    ;
}
