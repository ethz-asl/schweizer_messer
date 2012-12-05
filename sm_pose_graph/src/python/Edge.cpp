#include <sm/pose_graph/Edge.hpp>
#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/python/Id.hpp>


using namespace boost::python;
using namespace sm::pose_graph;


// local helper function for python export
const transformation_t & getTFromEdge(const Edge * e)
{
  return e->T_to_from();
}


void export_Edge()
{
    sm::python::Id_python_converter<EdgeId>::register_converter();

    class_<Edge>("Edge",init<>())
        .def(init<EdgeId,VertexId,VertexId,transformation_t>("Edge(id, to, from, T_to_from)"))
        .def("setId", &Edge::setId)
        .def("id", &Edge::id)
        .def("to", &Edge::to)
        .def("from", &Edge::from)
        .def("T_to_from", getTFromEdge, return_value_policy<copy_const_reference>())
        .def("set_T_to_from", &Edge::set_T_to_from)
        .def("isBinaryEqual", &Edge::isBinaryEqual)
    ;
}
