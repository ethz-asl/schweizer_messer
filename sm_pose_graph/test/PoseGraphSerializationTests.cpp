#include "test_help.hpp"
 // Bring in my package's API, which is what I'm testing

TEST(PoseGraphSerializationSuite, testVertexId)
{
  id_type id = 100;
  VertexId V1(id);

  {
    std::ofstream ofs("test.ba", std::ios::binary);
    boost::archive::binary_oarchive oa(ofs);
  
    oa << V1;
  
  }


  VertexId V2;
  ASSERT_NE(V1,V2);
  {
    std::ifstream ifs("test.ba", std::ios::binary);
    boost::archive::binary_iarchive ia(ifs);
  
    ia >> V2;
  }  
  
  ASSERT_EQ(V1,V2);
  ASSERT_EQ(V1.getId(),id);
  ASSERT_EQ(V2.getId(),id);
}

TEST(PoseGraphSerializationSuite, testVertex)
{
  id_type id = 100;
  VertexId vid(id);
  ros::Time time(100.12);
  Vertex V1(vid, time);
  V1.set_T_topocentric_vehicle(randomT());
  V1.setSubgraphId(SubgraphId(20));

  ASSERT_FALSE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),0);
  V1.addMeasurement(randomAM());
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),1);
  V1.addMeasurement(randomAM());
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),2);

  {
    std::ofstream ofs("test.ba", std::ios::binary);
    boost::archive::binary_oarchive oa(ofs);
  
    oa << V1;
  
  }

  Vertex V2;
  ASSERT_NE(V1.id(),V2.id());
  {
    std::ifstream ifs("test.ba", std::ios::binary);
    boost::archive::binary_iarchive ia(ifs);
    
    ia >> V2;
  }  
  
  checkEqual(V1,V2);
  ASSERT_EQ(V1.id().getId(),id);
  ASSERT_EQ(V2.id().getId(),id);


  {
    std::ifstream ifs("test.ba", std::ios::binary);
    boost::archive::binary_iarchive ia(ifs);
    
    ia >> V2;
  }  
  
  checkEqual(V1,V2);
  ASSERT_EQ(V1.id().getId(),id);
  ASSERT_EQ(V2.id().getId(),id);
  
}



TEST(PoseGraphSerializationSuite, testEdgeId)
{
  id_type id = 100;
  EdgeId E1(id);
  {
    std::ofstream ofs("test.ba", std::ios::binary);
    boost::archive::binary_oarchive oa(ofs);
  
    oa << E1;
  
  }


  EdgeId E2;
  ASSERT_NE(E1,E2);
  {
    std::ifstream ifs("test.ba", std::ios::binary);
    boost::archive::binary_iarchive ia(ifs);
  
    ia >> E2;
  }  
  
  ASSERT_EQ(E1,E2);
  ASSERT_EQ(E1.getId(),id);
  ASSERT_EQ(E2.getId(),id);

}



TEST(PoseGraphSerializationSuite, testEdge)
{

  
  Transformation T;
  T.T() = Eigen::AngleAxisd(0.1, Eigen::Vector3d::UnitZ())
    * Eigen::AngleAxisd(0.2, Eigen::Vector3d::UnitY())
    * Eigen::AngleAxisd(0.3, Eigen::Vector3d::UnitZ()) * Eigen::Translation3d(0.1,0.2,0.3);

  VertexId from(250), to(120);
  EdgeId id(12);

  Edge E1(id, from, to, T);
  ASSERT_FALSE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),0);
  E1.addMeasurement(randomRM());
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),1);
  E1.addMeasurement(randomRM());
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),2);

  {
    std::ofstream ofs("test.ba", std::ios::binary);
     boost::archive::binary_oarchive oa(ofs);
  
     oa << E1;
  
  }


  Edge E2;
  ASSERT_NE(E1.id(),E2.id());
   {
     std::ifstream ifs("test.ba", std::ios::binary);
     boost::archive::binary_iarchive ia(ifs);
  
     ia >> E2;
   }  
  
   checkEqual(E1,E2);

   // Try this a second time...We had probems with serializing the boost graph
   {
     std::ifstream ifs("test.ba", std::ios::binary);
     boost::archive::binary_iarchive ia(ifs);
  
     ia >> E2;
   }  
  
   checkEqual(E1,E2);

}


TEST(PoseGraphSerializationSuite, testEdgeRm)
{

  
  Transformation T;
  T.T() = Eigen::AngleAxisd(0.1, Eigen::Vector3d::UnitZ())
    * Eigen::AngleAxisd(0.2, Eigen::Vector3d::UnitY())
    * Eigen::AngleAxisd(0.3, Eigen::Vector3d::UnitZ()) * Eigen::Translation3d(0.1,0.2,0.3);

  VertexId from(250), to(120);
  EdgeId id(12);

  Edge E1(id, from, to, T);
  ASSERT_FALSE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),0);
  RelativeMeasurement rm0 = randomRM();
  E1.addMeasurement( rm0 );
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),1);
  RelativeMeasurement rm1 = randomRM();
  E1.addMeasurement( rm1 );
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),2);
  RelativeMeasurement rm2 = randomRM();
  E1.addMeasurement( rm2 );
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),3);
  
  Edge::measurement_list_t::const_iterator i1 = E1.measurementsBegin();
  i1++;
  E1.removeMeasurement(i1);
  i1 = E1.measurementsBegin();
  checkEqual(*i1,rm0);
  i1++;
  checkEqual(*i1,rm2);
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),2);

  i1 = E1.measurementsBegin();
  E1.removeMeasurement(i1);
  ASSERT_TRUE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),1);
  i1 = E1.measurementsBegin();
  checkEqual(*i1,rm2);

  i1 = E1.measurementsBegin();
  E1.removeMeasurement(i1);
  ASSERT_FALSE(E1.hasMeasurements());
  ASSERT_EQ(E1.numMeasurements(),0);

}




TEST(PoseGraphSerializationSuite, testRelativeMeasurement)
{
  
  RelativeMeasurement::measurement_t m;
  m << 1,2,3,4,5,6;
  RelativeMeasurement::inv_covariance_t U;
  U <<  1,  2,  3,  4,  5,  6, 
        7,  8,  9, 10, 11, 12, 
       13, 14, 15, 16, 17, 18, 
       19, 20, 21, 22, 23, 24,
       25, 26, 27, 28, 29, 30, 
       31, 32, 33, 34, 35, 36;
  std::string frameId = "camera";

  RelativeMeasurement R1(m,U,frameId);
  asrl::io::save(R1,"test.ba");
  
  RelativeMeasurement R2;
  asrl::io::load(R2,"test.ba");
  checkEqual(R1,R2);
}


TEST(PoseGraphSerializationSuite, testAbsoluteMeasurement)
{
  
  AbsoluteMeasurement A1 = randomAM();
  asrl::io::save(A1,"test.ba");
  
  AbsoluteMeasurement A2;
  asrl::io::load(A2,"test.ba");
  checkEqual(A1,A2);
}




TEST(PoseGraphSerializationSuite,poseGraphSerializationTest)
{
  PoseGraph G1;
  Transformation::covariance_t U;
  U <<  1,  2,  3,  4,  5,  6, 
        7,  8,  9, 10, 11, 12, 
       13, 14, 15, 16, 17, 18, 
       19, 20, 21, 22, 23, 24,
       25, 26, 27, 28, 29, 30, 
       31, 32, 33, 34, 35, 36;

  G1.set_T_vehicle_sensor("camera", randomT());
  G1.set_T_vehicle_sensor("inclinometer", randomT());

  // Simple linear graph
  for(int i = 0; i < 10; i++)
    {
      ros::Time t(i + 0.11);
      G1.addVertex(VertexId(i),t);
      G1.addAbsoluteMeasurement(VertexId(i),randomAM());
      G1.addAbsoluteMeasurement(VertexId(i),randomAM());
      if(i > 0)
	{
	  Transformation T;
	  T.T() = Eigen::AngleAxisd(0.1, Eigen::Vector3d::UnitZ())
	    * Eigen::AngleAxisd(0.2, Eigen::Vector3d::UnitY())
	    * Eigen::AngleAxisd(0.3, Eigen::Vector3d::UnitZ()) * Eigen::Translation3d(0.1,0.2,0.3);
	  T.U() = U * i;
	  EdgeId eid = G1.addEdge(VertexId(i-1),VertexId(i),T);
          G1.addRelativeMeasurement(eid,randomRM());
          G1.addRelativeMeasurement(eid,randomRM());
	}
    }


  G1.save("test.ba");

  PoseGraph G2;
  
  G2.load("test.ba");

  // Now...how do I compare the graphs?
  checkEqual(G1,G2);

  G2.load("test.ba");
  checkEqual(G1,G2);
}



TEST(PoseGraphSerializationSuite, testVertexAm)
{
  id_type id = 100;
  VertexId vid(id);
  ros::Time time(100.12);
  Vertex V1(vid, time);

  ASSERT_FALSE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),0);
  AbsoluteMeasurement am0 = randomAM();
  V1.addMeasurement( am0 );
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),1);
  AbsoluteMeasurement am1 = randomAM();
  V1.addMeasurement( am1 );
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),2);
  AbsoluteMeasurement am2 = randomAM();
  V1.addMeasurement( am2 );
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),3);
  
  Vertex::measurement_list_t::const_iterator i1 = V1.measurementsBegin();
  i1++;
  V1.removeMeasurement(i1);
  i1 = V1.measurementsBegin();
  checkEqual(*i1,am0);
  i1++;
  checkEqual(*i1,am2);
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),2);

  i1 = V1.measurementsBegin();
  V1.removeMeasurement(i1);
  ASSERT_TRUE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),1);
  i1 = V1.measurementsBegin();
  checkEqual(*i1,am2);

  i1 = V1.measurementsBegin();
  V1.removeMeasurement(i1);
  ASSERT_FALSE(V1.hasMeasurements());
  ASSERT_EQ(V1.numMeasurements(),0);

}

