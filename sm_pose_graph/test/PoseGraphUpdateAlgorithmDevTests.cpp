 // Bring in my package's API, which is what I'm testing
#include <sm/math/Transformation.hpp>
#include <Eigen/Core>
// Bring in gtest
#include <gtest/gtest.h>
#include <boost/cstdint.hpp>

#include <sm/string_routines.hpp>
#include <sm/pose_graph/PoseGraph.hpp>
#include <sm/math/transformations.hpp>
#include <sm/eigen/GTest.hpp>
#include <sm/pose_graph/Exceptions.hpp>
#include <boost/foreach.hpp>
using namespace sm::pose_graph;
using namespace sm;
using namespace sm::math;





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
      ros::Time t(i + 0.1);
      graph.addVertex(VertexId(i),t);
    }

  Eigen::Matrix<double,6,1> udiag;
  udiag << 0.1 ,0.1 ,0.1,    // Translation
    0.01,0.01,0.01;   // Rotation
  Eigen::Matrix<double,6,6> U = udiag.asDiagonal();
      

  // Add the edges: addEdge(to,from,T_to_from
  graph.addEdge (VertexId(2), VertexId(1),   Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*1));
  graph.addEdge (VertexId(2), VertexId(3),   Transformation(toTEuler( 1, 0, 0, 0, 0, 0), U*2));
  graph.addEdge (VertexId(4), VertexId(3),   Transformation(toTEuler(-1, 1, 0, 0, 0, 0), U*3));
  graph.addEdge (VertexId(6), VertexId(3),   Transformation(toTEuler(-1,-1, 0, 0, 0, 0), U*4));
  graph.addEdge (VertexId(5), VertexId(4),   Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*5));
  graph.addEdge (VertexId(7), VertexId(6),   Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*6));
  graph.addEdge (VertexId(8), VertexId(7),   Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*7));
  graph.addEdge (VertexId(9), VertexId(8),   Transformation(toTEuler( 0, 1, 0, 0, 0, 0), U*8));
  graph.addEdge (VertexId(9), VertexId(5),   Transformation(toTEuler(-1,-1, 0, 0, 0, 0), U*9));
  graph.addEdge (VertexId(10), VertexId(9),  Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*10));  
  graph.addEdge (VertexId(11), VertexId(10), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*11));
  graph.addEdge (VertexId(14), VertexId(11), Transformation(toTEuler( 1,-2, 0, 0, 0, 0), U*12));
  graph.addEdge (VertexId(12), VertexId(6),  Transformation(toTEuler(-1,-1, 0, 0, 0, 0), U*13));
  graph.addEdge (VertexId(13), VertexId(12), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*14));
  graph.addEdge (VertexId(14), VertexId(13), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*15));
  graph.addEdge (VertexId(14), VertexId(15), Transformation(toTEuler( 1, 0, 0, 0, 0, 0), U*16));
  graph.addEdge (VertexId(16), VertexId(15), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*17));
  graph.addEdge (VertexId(18), VertexId(17), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*18));
  graph.addEdge (VertexId(19), VertexId(18), Transformation(toTEuler(-1, 0, 0, 0, 0, 0), U*19));



  // This works.

}


TEST(PoseGraphTestSuite, testEdges)
{
  PoseGraph poseGraph;
  
  populateTestPoseGraph(poseGraph);
  //poseGraph.writeGraphViz("testGraph.dot");
  

  // Go through the edges checking that they are labeled correctly.
  EdgeSet edges = poseGraph.allEdges();
  BOOST_FOREACH(const EdgeId & e, edges)
    {
      const Edge & edge = poseGraph.getEdge(e);
      VertexId vfrom = edge.from();
      VertexId vto = edge.to();
      
      const Edge & edge2 = poseGraph.getEdge(vfrom, vto);
      ASSERT_EQ(&edge, &edge2);
      const Edge & edge3 = poseGraph.getEdge(vto, vfrom);
      ASSERT_EQ(&edge, &edge3);

      // // Check that we can look up the same edge
      // std::pair<const Edge *, bool> result1 = poseGraph.getEdgeInternal(graph[vto].id(),graph[vfrom].id());
      // ASSERT_EQ(result1.first,&graph[*ei]);
      // // And that we don't have to invert the transformation matrix
      // ASSERT_FALSE(result1.second);

      // // Check that we can look up the same edge in reverse
      // std::pair<const Edge *, bool> result2 = poseGraph.getEdgeInternal(graph[vfrom].id(),graph[vto].id());
      // ASSERT_EQ(result2.first,&graph[*ei]);
      // // And that we do have to invert the transformation matrix
      // ASSERT_TRUE(result2.second);

      // // Check with the mid-level routines.
      // std::pair<PoseGraph::graph_edge_t, bool> result3 = poseGraph.getEdgeInternal(graph[vto].id(),vfrom);
      // ASSERT_EQ(result3.first,*ei);
      // // And that we don't have to invert the transformation matrix
      // ASSERT_FALSE(result3.second);

      // // Check with the mid-level routines.
      // std::pair<PoseGraph::graph_edge_t, bool> result4 = poseGraph.getEdgeInternal(graph[vfrom].id(),vto);
      // ASSERT_EQ(result4.first,*ei);
      // // And that we do have to invert the transformation matrix
      // ASSERT_TRUE(result4.second);
    }
  
}



typedef Eigen::Matrix<double, 6,1> trans_t;

void testBfsResult(PoseGraph & pg,
                   LocalizationChain & lc,
		   VertexId expectedPath[],
		   int expectedPathSize,
		   trans_t expectedTransformation_0N,
                   std::string frameId = "vehicle")
{


  ASSERT_EQ((int)lc.path().size(),expectedPathSize) 
    << "Expected Path: " << asrl::arrToString(expectedPath,expectedPath + expectedPathSize) 
    << "\nActual Path:   " << asrl::arrToString(lc.path().begin(), lc.path().end());
   for(unsigned i = 0; i < lc.path().size(); i++)
    {
      ASSERT_EQ(lc.path()[i],expectedPath[i]) 
	<< "Path element " << i << " failed the vertex id equality test\n"
	<< "Expected Path: " << asrl::arrToString(expectedPath,expectedPath + expectedPathSize) 
	<< "\nActual Path:   " << asrl::arrToString(lc.path().begin(), lc.path().end());

    }
  
  ASSERT_EQ(lc.branchIndex(),(int)lc.path().size() - 1);

  trans_t t_0N = asrl::math::fromTEuler(lc.T_start_branch().T().matrix());
  trans_t t_NJ = asrl::math::fromTEuler(lc.T_branch_end().T().matrix());
  trans_t t_Nk = asrl::math::fromTEuler(lc.T_branch_leaf().T().matrix());

  trans_t z6 = trans_t::Zero();

  for(int i = 0; i < 6; i++)
    {
      ASSERT_NEAR(t_0N[i],expectedTransformation_0N[i],1e-10) << "the shortest path transformation\n" 
						     << t_0N << "\ndoes not match the expected transformation\n" 
						     << expectedTransformation_0N;
      ASSERT_NEAR(t_NJ[i],0.0, 1e-10) << "The tail transformation should be zero:\n" << t_NJ;
      ASSERT_NEAR(t_Nk[i],0.0, 1e-10) << "The branch transformation should be zero:\n" << t_Nk; 
    }

  // Check that the topocentric transformations are in sync.
  if(lc.path().size() > 0)
    {
      const Vertex & V0 = pg.getVertex(lc.path()[0]);
      const Vertex & VN = pg.getVertex(lc.path()[lc.path().size() - 1]);
      Transformation T_0N = lc.T_sensor_vehicle().composeWith(V0.T_topocentric_vehicle().inverse().composeWith(VN.T_topocentric_vehicle())).composeWith(lc.T_vehicle_sensor());
      asrl::eigen::assertNear(expectedTransformation_0N,asrl::math::fromTEuler(T_0N.T().matrix()), 1e-10, ASRL_SOURCE_FILE_POS);

      T_0N = pg.getTransformation(lc.path()[0],lc.path()[lc.path().size() - 1]);
      T_0N = lc.T_sensor_vehicle().composeWith(T_0N).composeWith(lc.T_vehicle_sensor());
      asrl::eigen::assertNear(expectedTransformation_0N,asrl::math::fromTEuler(T_0N.T().matrix()), 1e-10, ASRL_SOURCE_FILE_POS);
    }
}


TEST(PoseGraphTestSuite, testBfs)
{
  PoseGraph poseGraph;
  populateTestPoseGraph(poseGraph);
  
  {
    const int pathLength = 5;
    // 4 - 5 - 9 - 10 - 11  
    VertexId answer[pathLength] = {VertexId(4), VertexId(5), VertexId(9), VertexId(10), VertexId(11) };
    trans_t t_0N;
    t_0N << 4,1,0,0,0,0;
   
    LocalizationChain lc = poseGraph.breadthFirstSearch(VertexId(4), VertexId(11));
    testBfsResult(poseGraph,lc,answer,pathLength,t_0N);
    std::reverse(answer,answer + pathLength);
    t_0N = -t_0N;
    lc = poseGraph.breadthFirstSearch(answer[0], answer[pathLength-1]);
    testBfsResult(poseGraph,lc,answer,pathLength,t_0N);
  }



  {
    LocalizationChain lc = poseGraph.breadthFirstSearch(VertexId(1), VertexId(16));
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
    testBfsResult(poseGraph,lc,answer,pathLength,t_0N);
    std::reverse(answer,answer + pathLength);
    t_0N = -t_0N;
    lc = poseGraph.breadthFirstSearch(answer[0], answer[pathLength-1]);
    testBfsResult(poseGraph,lc,answer,pathLength,t_0N);
  }
}

TEST(PoseGraphTestSuite, testLocalizationChainIncDec)
{
  PoseGraph poseGraph;
  populateTestPoseGraph(poseGraph);
  

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
  
  
  LocalizationChain lc;
  ASSERT_NO_THROW(lc = poseGraph.breadthFirstSearch(VertexId(1), VertexId(16)));
  testBfsResult(poseGraph,lc,answer,pathLength,t_0N);


  ASSERT_THROW(poseGraph.increment(lc),std::runtime_error);
  ASSERT_EQ(lc.branchIndex(), lc.path().size() - 1) << "Even though the increment fails, the branch index should remain in-bounds";

  std::cout << "Path [";
  const std::vector<VertexId> & path = lc.path();
  for(unsigned i = 0; i < path.size(); i++)
    {
      std::cout << path[i] << " ";
    }
  std::cout << "]\n";
  std::cout << "Branch index: " << lc.branchIndex() << std::endl;
  std::cout << "Branch id:    " << lc.branchId() << std::endl;
  std::cout << "Path id:      " << lc.pathId() << std::endl;
  

  int N = pathLength - 1;
  while(N != 0)
    {
      --N;
      std::cout << "Decrement " << N << std::endl;
      ASSERT_NO_THROW(poseGraph.decrement(lc));
      std::cout << "Bfs: " << answer[0] << " --> " << answer[N] << std::endl;
      LocalizationChain lc2;
      ASSERT_NO_THROW(lc2 = poseGraph.breadthFirstSearch(answer[0], answer[N]));
      
      ASSERT_EQ(lc.branchIndex(),N);
      asrl::eigen::assertNear(lc.T_start_branch().T().matrix(),lc2.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_start_branch().U().matrix(),lc2.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

      // Test the leaf transformation under decrement.
      // The leaf is at answer[pathLength-1] with zero uncertainty.
      std::cout << "Bfs: " << answer[N] << " --> " << answer[pathLength-1] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[N], answer[pathLength - 1]);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      
      

    }

  ASSERT_THROW(poseGraph.decrement(lc), std::runtime_error);
  
  while(N < (pathLength - 1))
    {
      ++N; 
      ASSERT_NO_THROW(poseGraph.increment(lc));
      std::cout << "Bfs: " << answer[0] << " --> " << answer[N] << std::endl;
      LocalizationChain lc2;
      ASSERT_NO_THROW(lc2 = poseGraph.breadthFirstSearch(answer[0], answer[N]));
      
      ASSERT_EQ(lc.branchIndex(),N);
      asrl::eigen::assertNear(lc.T_start_branch().T().matrix(),lc2.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_start_branch().U().matrix(),lc2.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

      // Test the leaf transformation under decrement.
      // The leaf is at answer[pathLength-1] with zero uncertainty.
      std::cout << "Bfs: " << answer[N] << " --> " << answer[pathLength-1] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[N], answer[pathLength - 1]);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      // This should fail because the uncertainty for the branch/leaf transformation grows without bound
      //asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

 
    }

  ASSERT_THROW(poseGraph.increment(lc), std::runtime_error);


  // Now set up the branch/leaf transformation differently to test it.
  while(lc.branchIndex() > 0)
    {
      ASSERT_NO_THROW(poseGraph.decrement(lc));
    }


  // Test the leaf transformation under increment.
  // The leaf is now at pose 0 with zero uncertainty.
  // This case was tested for the decrement operation in the initial decrement above.
  ASSERT_NO_THROW(lc.setLeafToBranchTransformation(asrl::math::Transformation(Eigen::Matrix4d::Identity(), Eigen::Matrix<double,6,6>::Zero())));
  while(lc.branchIndex() < ((int)lc.pathLength() - 1))
    {
      ASSERT_NO_THROW(poseGraph.increment(lc));
      std::cout << "Bfs: " << answer[lc.branchIndex()] << " --> " << answer[0] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[lc.branchIndex()],answer[0]);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      
    }

}


TEST(PoseGraphTestSuite, testDisconnected)
{
  PoseGraph poseGraph;
  populateTestPoseGraph(poseGraph);
  
  // nodes 1-16 are all connected. 17,18, and 19 are connected but the two subgraphs are not connected
  for(int i = 1; i <=16; i++)
    {
      for(int j = 17; j <= 19; j++)
	{
	  ASSERT_THROW(poseGraph.breadthFirstSearch(VertexId(i),VertexId(j)),asrl::pose_graph::NoPathFound) 
	    << "BFS was able to find a path between disconnected nodes " << i << " and " << j;
	}
    }

  // subgraph 1
  for(int i = 1; i <=16; i++)
    {
      for(int j = 1; j <= 16; j++)
	{
	  ASSERT_NO_THROW(poseGraph.breadthFirstSearch(VertexId(i),VertexId(j))) 
	    << "BFS was not able to find a path between connected nodes " << i << " and " << j;
	}
    }

  // subgraph 2
  for(int i = 17; i <=19; i++)
    {
      for(int j = 17; j <= 19; j++)
	{
	  ASSERT_NO_THROW(poseGraph.breadthFirstSearch(VertexId(i),VertexId(j))) 
	    << "BFS was not able to find a path between connected nodes " << i << " and " << j;
	}
    }
 
}


TEST(PoseGraphTestSuite, testUpdateLocalizationChain)
{
  
  PoseGraph poseGraph;
  populateTestPoseGraph(poseGraph);

  LocalizationChain chain = poseGraph.breadthFirstSearch(VertexId(10),VertexId(1));  
  
  Transformation T_k_kp1(toTEuler(1.0/3.0,0.0,0,0,0,0));
  Transformation T_1_k(toTEuler(-0.0,-0.6,0,0,0,0));
  Transformation T_1_k_built;
  Transformation T_b_k = T_1_k;

  ASSERT_EQ(chain.branchId(),VertexId(1));
  chain.setLeafToBranchTransformation(T_1_k);

  std::cout << "Step 0: T_1_k\n" << T_1_k.T().matrix() << std::endl;

  // Take the first step.
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);

  std::cout << "Step 1: T_1_k\n" << T_1_k.T().matrix() << std::endl;

  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(1));
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  



  // Take the second step.
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  asrl::math::Transformation T_2_1 =  poseGraph.getEdgeTransformation(VertexId(2), VertexId(1));
  T_b_k = T_2_1.composeWith(T_b_k.composeWith(T_k_kp1));
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 2: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(2)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  

  // Third step is still Vertex 2
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 3: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(2)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // Fourth step is still Vertex 2
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 4: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(2)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // Fifth step is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  asrl::math::Transformation T_3_2 =  poseGraph.getEdgeTransformation(VertexId(3), VertexId(2));
  T_b_k = T_3_2.composeWith(T_b_k.composeWith(T_k_kp1));
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 5: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  

  // sixth step is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 6: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  

  // seventh step is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 7: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // eighth step is V4
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  asrl::math::Transformation T_4_3 =  poseGraph.getEdgeTransformation(VertexId(4), VertexId(3));
  T_b_k = T_4_3.composeWith(T_b_k.composeWith(T_k_kp1));
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 8: T_1_k\n" << T_1_k.T().matrix() << std::endl;

  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(4)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  

  
  // Reverse Direction
  T_k_kp1 = T_k_kp1.inverse();

  // ninth step is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  asrl::math::Transformation T_3_4 =  poseGraph.getEdgeTransformation(VertexId(3), VertexId(4));
  T_b_k = T_3_4.composeWith(T_b_k.composeWith(T_k_kp1));
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 9: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  std::cout << "T_1_3:\n" << chain.T_branch_end().inverse().T().matrix() 
	    << "\nT_3_leaf:\n" << chain.T_branch_leaf().T().matrix() << std::endl;
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // tenth is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 7: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // eleven is V3
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);  
  T_b_k = T_b_k.composeWith(T_k_kp1);
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 7: T_1_k\n" << T_1_k.T().matrix() << std::endl;
  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(3)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // twelve is V2
  poseGraph.updateLocalizationChain(chain,T_k_kp1,2);
  asrl::math::Transformation T_2_3 =  poseGraph.getEdgeTransformation(VertexId(2), VertexId(3));
  T_b_k = T_2_3.composeWith(T_b_k.composeWith(T_k_kp1));
  T_1_k = T_1_k.composeWith(T_k_kp1);
  std::cout << "Step 8: T_1_k\n" << T_1_k.T().matrix() << std::endl;

  T_1_k_built = chain.T_branch_end().inverse().composeWith(chain.T_branch_leaf());
  asrl::eigen::assertNear(T_1_k.T().matrix(),T_1_k_built.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  
  // Check that is was correct.
  ASSERT_EQ(chain.branchId(),VertexId(2)) << "T_1_k:\n:" << T_1_k.T().matrix();
  asrl::eigen::assertNear(chain.T_branch_leaf().T().matrix(),T_b_k.T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);  


  // Now step back.
 }


TEST(PoseGraphTestSuite, testSubgraph)
{
  PoseGraph poseGraph;
  asrl::math::Transformation T;  

  // Create a subgraph.
  VertexId vid1 = poseGraph.addVertex(ros::Time(0.1));
  ASSERT_FALSE(poseGraph.getVertex(vid1).subgraphId().isSet());

  VertexId vid2 = poseGraph.addVertex(ros::Time(0.2));
  ASSERT_FALSE(poseGraph.getVertex(vid2).subgraphId().isSet());
  ASSERT_FALSE(poseGraph.getVertex(vid1).subgraphId().isSet());
    
  // The subgraph id gets added when the edge is added.
  poseGraph.addEdge(vid1,vid2,T);
  ASSERT_TRUE(poseGraph.getVertex(vid1).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid2).subgraphId().isSet());

  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid2).subgraphId());
  
  // Connect up to the subgraph
  VertexId vid3 = poseGraph.addVertex(ros::Time(0.1));
  ASSERT_FALSE(poseGraph.getVertex(vid3).subgraphId().isSet());

  // Call with the disconnected vertex in the left slot.
  poseGraph.addEdge(vid3,vid2,T);
  ASSERT_TRUE(poseGraph.getVertex(vid1).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid2).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid3).subgraphId().isSet());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid2).subgraphId());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid3).subgraphId());

  VertexId vid4 = poseGraph.addVertex(ros::Time(0.2));
  ASSERT_FALSE(poseGraph.getVertex(vid4).subgraphId().isSet());
  // Call with the disconnected vertex in the right slot.
  poseGraph.addEdge(vid2,vid4,T);
  ASSERT_TRUE(poseGraph.getVertex(vid1).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid2).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid3).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid4).subgraphId().isSet());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid2).subgraphId());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid3).subgraphId());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid4).subgraphId());

  // Now test adding between two edges already on the same subgraph
  poseGraph.addEdge(vid1,vid4,T);
  ASSERT_TRUE(poseGraph.getVertex(vid1).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid2).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid3).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid4).subgraphId().isSet());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid2).subgraphId());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid3).subgraphId());
  ASSERT_EQ(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid4).subgraphId());

  // Now create a disconnected subgraph.
  VertexId vid5 = poseGraph.addVertex(ros::Time(0.2));
  ASSERT_FALSE(poseGraph.getVertex(vid5).subgraphId().isSet());
  
  VertexId vid6 = poseGraph.addVertex(ros::Time(0.2));
  ASSERT_FALSE(poseGraph.getVertex(vid6).subgraphId().isSet());

  poseGraph.addEdge(vid5,vid6,T);
  ASSERT_TRUE(poseGraph.getVertex(vid5).subgraphId().isSet());
  ASSERT_TRUE(poseGraph.getVertex(vid6).subgraphId().isSet());
  ASSERT_EQ(poseGraph.getVertex(vid5).subgraphId(),poseGraph.getVertex(vid6).subgraphId());
  ASSERT_NE(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid5).subgraphId());
  ASSERT_NE(poseGraph.getVertex(vid1).subgraphId(),poseGraph.getVertex(vid6).subgraphId());

  // Now verify that connecting two subgraphs doesn't work.
  ASSERT_THROW(poseGraph.addEdge(vid1,vid5,T),PoseGraphException);

}


TEST(PoseGraphTestSuite, testLocalizationChainIncDecWithFrame)
{
  PoseGraph poseGraph;
  populateTestPoseGraph(poseGraph);
  std::string frameId = "camera";

  Eigen::Matrix4d T_v_s = toTEuler(Eigen::Matrix<double,6,1>::Random());
  Eigen::Matrix4d T_s_v = T_v_s.inverse();

  poseGraph.set_T_vehicle_sensor(frameId,T_v_s);  

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
  // Convert this answer to the sensor frame
  t_0N = fromTEuler( T_s_v *  toTEuler(t_0N) * T_v_s );
  
  LocalizationChain lc(frameId, T_v_s);
  ASSERT_NO_THROW(lc = poseGraph.breadthFirstSearch(VertexId(1), VertexId(16), frameId));
  testBfsResult(poseGraph,lc,answer,pathLength,t_0N);


  ASSERT_THROW(poseGraph.increment(lc),std::runtime_error);
  ASSERT_EQ(lc.branchIndex(), lc.path().size() - 1) << "Even though the increment fails, the branch index should remain in-bounds";

  std::cout << "Path [";
  const std::vector<VertexId> & path = lc.path();
  for(unsigned i = 0; i < path.size(); i++)
    {
      std::cout << path[i] << " ";
    }
  std::cout << "]\n";
  std::cout << "Branch index: " << lc.branchIndex() << std::endl;
  std::cout << "Branch id:    " << lc.branchId() << std::endl;
  std::cout << "Path id:      " << lc.pathId() << std::endl;
  

  int N = pathLength - 1;
  while(N != 0)
    {
      --N;
      std::cout << "Decrement " << N << std::endl;
      ASSERT_NO_THROW(poseGraph.decrement(lc));
      std::cout << "Bfs: " << answer[0] << " --> " << answer[N] << std::endl;
      LocalizationChain lc2;
      ASSERT_NO_THROW(lc2 = poseGraph.breadthFirstSearch(answer[0], answer[N], frameId));
      
      ASSERT_EQ(lc.branchIndex(),N);
      asrl::eigen::assertNear(lc.T_start_branch().T().matrix(),lc2.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_start_branch().U().matrix(),lc2.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

      // Test the leaf transformation under decrement.
      // The leaf is at answer[pathLength-1] with zero uncertainty.
      std::cout << "Bfs: " << answer[N] << " --> " << answer[pathLength-1] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[N], answer[pathLength - 1], frameId);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      
      

    }

  ASSERT_THROW(poseGraph.decrement(lc), std::runtime_error);
  
  while(N < (pathLength - 1))
    {
      ++N; 
      ASSERT_NO_THROW(poseGraph.increment(lc));
      std::cout << "Bfs: " << answer[0] << " --> " << answer[N] << std::endl;
      LocalizationChain lc2;
      ASSERT_NO_THROW(lc2 = poseGraph.breadthFirstSearch(answer[0], answer[N],frameId));
      
      ASSERT_EQ(lc.branchIndex(),N);
      asrl::eigen::assertNear(lc.T_start_branch().T().matrix(),lc2.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_start_branch().U().matrix(),lc2.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

      // Test the leaf transformation under decrement.
      // The leaf is at answer[pathLength-1] with zero uncertainty.
      std::cout << "Bfs: " << answer[N] << " --> " << answer[pathLength-1] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[N], answer[pathLength - 1], frameId);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      // This should fail because the uncertainty for the branch/leaf transformation grows without bound
      //asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_end().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);

 
    }

  ASSERT_THROW(poseGraph.increment(lc), std::runtime_error);


  // Now set up the branch/leaf transformation differently to test it.
  while(lc.branchIndex() > 0)
    {
      ASSERT_NO_THROW(poseGraph.decrement(lc));
    }


  // Test the leaf transformation under increment.
  // The leaf is now at pose 0 with zero uncertainty.
  // This case was tested for the decrement operation in the initial decrement above.
  ASSERT_NO_THROW(lc.setLeafToBranchTransformation(asrl::math::Transformation(Eigen::Matrix4d::Identity(), Eigen::Matrix<double,6,6>::Zero())));
  while(lc.branchIndex() < ((int)lc.pathLength() - 1))
    {
      ASSERT_NO_THROW(poseGraph.increment(lc));
      std::cout << "Bfs: " << answer[lc.branchIndex()] << " --> " << answer[0] << std::endl;
      LocalizationChain leaf = poseGraph.breadthFirstSearch(answer[lc.branchIndex()],answer[0], frameId);
      asrl::eigen::assertNear(lc.T_branch_leaf().T().matrix(),leaf.T_start_branch().T().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      asrl::eigen::assertNear(lc.T_branch_leaf().U().matrix(),leaf.T_start_branch().U().matrix(),1e-8, ASRL_SOURCE_FILE_POS);
      
    }

}
