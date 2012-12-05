#include <sm/pose_graph/PoseGraph.hpp>
#include <sm/pose_graph/Exceptions.hpp>
#include <boost/foreach.hpp>
#include <boost/graph/dijkstra_shortest_paths.hpp>
#include <sm/assert_macros.hpp>
#include <boost/graph/graphviz.hpp>
#include <fstream>
#include <boost/graph/breadth_first_search.hpp>
#include <sm/kinematics/transformations.hpp>

// Serialization
#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <limits>

// Python
#include <numpy_eigen/boost_python_headers.hpp>

using namespace sm::pose_graph;
using namespace boost::python;


void populateTestPoseGraph(PoseGraph & graph)
{
    // Build a sample pose graph.
    //   2 |                       --> 12 --> 13 --> 14 <-- 15 --> 16
    //     |                      /                   A
    //   1 |                  /-> 6 --> 7 -->  8       \-----
    //     |                 /                 V            |
    // Y 0 |     1 --> 2 <-- 3              -> 9 --> 10 --> 11
    //     |                  \             /
    //  -1 |                  \-> 4 --> 5 /          17 --> 18 --> 19
    //     |
    //     ------------------------------------------------------------
    //          0     1     2    3     4      5     6      7        8
    //                               X

    // Add the vertices.
    for(int i = 1; i <= 19; i++)
    {
        graph.addVertex(VertexId(i));
    }

    // Add the edges: addEdge(to,from,T_to_from
    graph.addEdge (VertexId(2), VertexId(1),   sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(2), VertexId(3),   sm::kinematics::toTEuler( 1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(4), VertexId(3),   sm::kinematics::toTEuler(-1, 1, 0, 0, 0, 0));
    graph.addEdge (VertexId(6), VertexId(3),   sm::kinematics::toTEuler(-1,-1, 0, 0, 0, 0));
    graph.addEdge (VertexId(5), VertexId(4),   sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(7), VertexId(6),   sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(8), VertexId(7),   sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(9), VertexId(8),   sm::kinematics::toTEuler( 0, 1, 0, 0, 0, 0));
    graph.addEdge (VertexId(9), VertexId(5),   sm::kinematics::toTEuler(-1,-1, 0, 0, 0, 0));
    graph.addEdge (VertexId(10), VertexId(9),  sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(11), VertexId(10), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(14), VertexId(11), sm::kinematics::toTEuler( 1,-2, 0, 0, 0, 0));
    graph.addEdge (VertexId(12), VertexId(6),  sm::kinematics::toTEuler(-1,-1, 0, 0, 0, 0));
    graph.addEdge (VertexId(13), VertexId(12), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(14), VertexId(13), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(14), VertexId(15), sm::kinematics::toTEuler( 1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(16), VertexId(15), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(18), VertexId(17), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
    graph.addEdge (VertexId(19), VertexId(18), sm::kinematics::toTEuler(-1, 0, 0, 0, 0, 0));
}


// local helper function for python export
boost::python::list allEdges(PoseGraph * pg)
{
    boost::python::list t;
    PoseGraph::EdgeSet es = pg->allEdges();
    for(PoseGraph::EdgeSet::const_iterator e = es.begin(); e != es.end(); e++)
    {
        t.append(*e);
    }
    return t;
}


// local helper function for python export
boost::python::list allVertices(PoseGraph * pg)
{
    boost::python::list t;
    PoseGraph::VertexSet vs = pg->allVertices();
    for(PoseGraph::VertexSet::const_iterator v = vs.begin(); v != vs.end(); v++)
    {
        t.append(*v);
    }
    return t;
}


// local helper function for python export
boost::python::list incidentEdges (PoseGraph * pg, const VertexId & n)
{
    boost::python::list t;
    PoseGraph::EdgeSet es = pg->incidentEdges(n);
    for(PoseGraph::EdgeSet::const_iterator e = es.begin(); e != es.end(); e++)
    {
        t.append(*e);
    }
    return t;
}


// local helper function for python export
boost::python::tuple incidentVertices(PoseGraph * pg, EdgeId const & e)
{
    std::pair<VertexId, VertexId> vv = pg->incidentVertices(e);
    return boost::python::make_tuple(vv.first,vv.second);
}


// local helper function for python export
void writeGraphViz(PoseGraph * pg, std::string const & str)
{
    pg->writeGraphViz(str);
}


// local helper function for python export
Edge getEdge1(PoseGraph * pg, EdgeId e)
{
    return pg->getEdge(e);
}


// local helper function for python export
Edge getEdge2(PoseGraph * pg, VertexId v1, VertexId v2)
{
    return pg->getEdge(v1,v2);
}


// local helper function for python export
void save(PoseGraph * pg, std::string const & f)
{
    pg->save(f);
}


// local helper function for python export
void load(PoseGraph * pg, std::string const & f)
{
    pg->load(f);
}


void export_PoseGraph()
{
    VertexId (PoseGraph::*addVertex1)() = &PoseGraph::addVertex;
    void (PoseGraph::*addVertex2)(const VertexId id) = &PoseGraph::addVertex;

    EdgeId (PoseGraph::*addEdge1)(VertexId to, VertexId from, const transformation_t& T_to_from) = &PoseGraph::addEdge;
    void (PoseGraph::*addEdge2)(EdgeId id, VertexId to, VertexId from, const transformation_t& T_to_from) = &PoseGraph::addEdge;

    transformation_t (PoseGraph::*getEdgeTransformation)(VertexId from, VertexId to) const = &PoseGraph::getEdgeTransformation;

    bool (PoseGraph::*edgeExists1)(EdgeId e) const = &PoseGraph::edgeExists;
    bool (PoseGraph::*edgeExists2)(VertexId v1, VertexId v2) const = &PoseGraph::edgeExists;

    class_<PoseGraph>("PoseGraph",init<>())
        .def("addVertex", addVertex1)
        .def("addVertex", addVertex2)
        .def("addEdge", addEdge1)
        .def("addEdge", addEdge2)
        .def("updateEdgeTransformation", &PoseGraph::updateEdgeTransformation)
        .def("clearGraph", &PoseGraph::clearGraph)
        .def("getEdgeTransformation", getEdgeTransformation)
        .def("save", save)
        .def("load", load)
        .def("edgeExists", edgeExists1)
        .def("edgeExists", edgeExists2)
        .def("writeGraphViz", writeGraphViz)
        .def("getEdge", getEdge1)
        .def("getEdge", getEdge2)
        .def("getVertex", &PoseGraph::getVertex,return_value_policy<copy_const_reference>())
        .def("allEdges", allEdges)
        .def("allVertices", allVertices)
        .def("incidentEdges", incidentEdges)
        .def("incidentVertices", incidentVertices)
        ;

    def("populateTestPoseGraph",populateTestPoseGraph);
}
