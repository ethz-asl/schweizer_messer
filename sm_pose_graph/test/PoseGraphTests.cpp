// Bring in my package's API, which is what I'm testing
#include <sm/pose_graph/PoseGraph.hpp>
#include <Eigen/Core>
// Bring in gtest
#include <gtest/gtest.h>
#include <boost/cstdint.hpp>

#include <sm/eigen/gtest.hpp>
#include <boost/foreach.hpp>
#include <sm/kinematics/transformations.hpp>
#include <sm/kinematics/UncertainTransformation.hpp>
#include <sm/string_routines.hpp>
using namespace sm::pose_graph;
using namespace sm;
using namespace sm::kinematics;
typedef Eigen::Matrix<double,6,1> trans_t;


void populateTestPoseGraph(PoseGraph & graph)
{
    // Build a sample pose graph.
    //   2 |                       --> 12 --> 13 --> 14 <-- 15 --> 16
    //     |                      /                   A
    //   1 |                  /-> 6 --> 7 -->  8       \-----
    //     |                 /                 V            |
    // Y 0 |     1 --> 2 <-- 3              -> 9 --> 10 --> 11
    //     |                 \             /  
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

    Eigen::Matrix<double,6,1> udiag;
    udiag << 0.1 ,0.1 ,0.1,    // Translation
        0.01,0.01,0.01;   // Rotation
    Eigen::Matrix<double,6,6> U = udiag.asDiagonal();

    // Add the edges: addEdge(to,from,T_to_from
    graph.addEdge (VertexId(2), VertexId(1),   UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*1));
    graph.addEdge (VertexId(2), VertexId(3),   UncertainTransformation(toTEuler( 1, 0, 0, 0, 0, 0), U*2));
    graph.addEdge (VertexId(4), VertexId(3),   UncertainTransformation(toTEuler(-1, 1, 0, 0, 0, 0), U*3));
    graph.addEdge (VertexId(6), VertexId(3),   UncertainTransformation(toTEuler(-1,-1, 0, 0, 0, 0), U*4));
    graph.addEdge (VertexId(5), VertexId(4),   UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*5));
    graph.addEdge (VertexId(7), VertexId(6),   UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*6));
    graph.addEdge (VertexId(8), VertexId(7),   UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*7));
    graph.addEdge (VertexId(9), VertexId(8),   UncertainTransformation(toTEuler( 0, 1, 0, 0, 0, 0), U*8));
    graph.addEdge (VertexId(9), VertexId(5),   UncertainTransformation(toTEuler(-1,-1, 0, 0, 0, 0), U*9));
    graph.addEdge (VertexId(10), VertexId(9),  UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*10));  
    graph.addEdge (VertexId(11), VertexId(10), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*11));
    graph.addEdge (VertexId(14), VertexId(11), UncertainTransformation(toTEuler( 1,-2, 0, 0, 0, 0), U*12));
    graph.addEdge (VertexId(12), VertexId(6),  UncertainTransformation(toTEuler(-1,-1, 0, 0, 0, 0), U*13));
    graph.addEdge (VertexId(13), VertexId(12), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*14));
    graph.addEdge (VertexId(14), VertexId(13), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*15));
    graph.addEdge (VertexId(14), VertexId(15), UncertainTransformation(toTEuler( 1, 0, 0, 0, 0, 0), U*16));
    graph.addEdge (VertexId(16), VertexId(15), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*17));
    graph.addEdge (VertexId(18), VertexId(17), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*18));
    graph.addEdge (VertexId(19), VertexId(18), UncertainTransformation(toTEuler(-1, 0, 0, 0, 0, 0), U*19));



    // This works.

}


TEST(PoseGraphTestSuite, testEdges)
{
    PoseGraph poseGraph;
  
    populateTestPoseGraph(poseGraph);
    //poseGraph.writeGraphViz("testGraph.dot");
  

    // Go through the edges checking that they are labeled correctly.
    PoseGraph::EdgeSet edges = poseGraph.allEdges();
    BOOST_FOREACH(const EdgeId & e, edges)
    {
        const Edge & edge = poseGraph.getEdge(e);
        VertexId vfrom = edge.from();
        VertexId vto = edge.to();
      
        const Edge & edge2 = poseGraph.getEdge(vfrom, vto);
        ASSERT_EQ(&edge, &edge2);
        const Edge & edge3 = poseGraph.getEdge(vto, vfrom);
        ASSERT_EQ(&edge, &edge3);

    }
  
}



void testBfsResult(PoseGraph & pg,
                   std::vector<VertexId> & lc,
                   VertexId expectedPath[],
                   int expectedPathSize,
                   const trans_t & expectedTransformation_0N,
                   const sm::kinematics::UncertainTransformation & T_0N)
{
    trans_t t_0N = fromTEuler(T_0N.T());

    ASSERT_EQ((int)lc.size(),expectedPathSize) 
        << "Expected Path: " << sm::arrToString(expectedPath,expectedPath + expectedPathSize) 
        << "\nActual Path:   " << sm::arrToString(lc.begin(), lc.end());
    for(unsigned i = 0; i < lc.size(); i++)
    {
        ASSERT_EQ(lc[i],expectedPath[i]) 
            << "Path element " << i << " failed the vertex id equality test\n"
            << "Expected Path: " << sm::arrToString(expectedPath,expectedPath + expectedPathSize) 
            << "\nActual Path:   " << sm::arrToString(lc.begin(), lc.end());

    }
    

    ASSERT_DOUBLE_MX_EQ(expectedTransformation_0N, t_0N, 1e-2, "Nope");

   
}


TEST(PoseGraphTestSuite, testBfs)
{
    PoseGraph poseGraph;
    populateTestPoseGraph(poseGraph);
  
    {
        const int pathLength = 5;
        // 4 - 5 - 9 - 10 - 11  
        VertexId answer[pathLength] = {VertexId(4), VertexId(5), VertexId(9), VertexId(10), VertexId(11) };
        trans_t t_4_11;
        t_4_11 << 4,1,0,0,0,0;
   
        std::vector<VertexId> lc;
        sm::kinematics::UncertainTransformation T_4_11 = poseGraph.breadthFirstSearch(VertexId(4), VertexId(11), &lc);

        testBfsResult(poseGraph,lc,answer,pathLength,t_4_11, T_4_11);

        std::reverse(answer,answer + pathLength);
        trans_t t_11_4 = -t_4_11;
        sm::kinematics::UncertainTransformation T_11_4 = poseGraph.breadthFirstSearch(VertexId(11), VertexId(4), &lc);
        testBfsResult(poseGraph,lc,answer,pathLength,t_11_4, T_11_4);
    }



    
    {
        std::vector<VertexId> lc;
        sm::kinematics::UncertainTransformation T = poseGraph.breadthFirstSearch(VertexId(1), VertexId(16), &lc);
        // 4 - 5 - 9 - 10 - 11  
        const int pathLength = 9;
        VertexId answer[pathLength] = 
            {
                VertexId(1), 
                VertexId(2), 
                VertexId(3), 
                VertexId(6), 
                VertexId(12),
                VertexId(13),
                VertexId(14),
                VertexId(15),
                VertexId(16)
            };
        trans_t t_0N;
        t_0N << 8, 2, 0, 0, 0, 0;
        testBfsResult(poseGraph,lc,answer,pathLength,t_0N, T);
        std::reverse(answer,answer + pathLength);
        t_0N = -t_0N;
        T = poseGraph.breadthFirstSearch(answer[0], answer[pathLength-1], &lc);
        testBfsResult(poseGraph,lc,answer,pathLength,t_0N, T);
    }
    
}


TEST(PoseGraphTestSuite, testPoseGraphSerialization)
{
    try {
        PoseGraph PG1;
        populateTestPoseGraph(PG1);

        PG1.save("test.graph");
    
        PoseGraph PG2;
        ASSERT_FALSE(PG1.isBinaryEqual(PG2));
        ASSERT_FALSE(PG2.isBinaryEqual(PG1));
    
        PG2.load("test.graph");

        ASSERT_TRUE(PG1.isBinaryEqual(PG2));
        ASSERT_TRUE(PG2.isBinaryEqual(PG1));
    }
    catch(std::exception const & e)
    {
        FAIL() << e.what();
    }
}
