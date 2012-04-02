#include <gtest/gtest.h>
#include <sm/BoostPropertyTreeImplementation.hpp>
#include <boost/property_tree/xml_parser.hpp>


TEST(PTreeTestSuite, testBoostPTree)
{
  boost::property_tree::ptree ptree;
  
  ptree.put<double>("d",0.1);
  ptree.put<double>("d.d",0.2);
  ptree.put<int>("i",1);
  ptree.put<int>("i.i",2);
  ptree.put<bool>("b",true);
  ptree.put<bool>("b.b", false);
  ptree.put<std::string>("s","hello");
  ptree.put<std::string>("s.s","goodbye");
  
  boost::property_tree::write_xml("test.xml", ptree);

  try 
    {
      boost::shared_ptr<sm::BoostPropertyTreeImplementation> bbpt(new sm::BoostPropertyTreeImplementation);
      
      bbpt->loadXml("test.xml");
      sm::PropertyTree pt(bbpt);
      
      ASSERT_NEAR(pt.getDouble("d"), 0.1, 1e-16);
      ASSERT_NEAR(pt.getDouble("/d"), 0.1, 1e-16);
      ASSERT_NEAR(pt.getDouble("d/d"), 0.2, 1e-16);
      ASSERT_NEAR(pt.getDouble("/d/d"), 0.2, 1e-16);
      // Push a namespace on to the stack.
      sm::PropertyTree dpt(pt,"d");
      ASSERT_NEAR(dpt.getDouble("d"), 0.2, 1e-16);
      ASSERT_NEAR(dpt.getDouble("/d"), 0.1, 1e-16);
      ASSERT_NEAR(dpt.getDouble("/d/d"), 0.2, 1e-16);

      ASSERT_EQ(pt.getInt("i"), 1);
      ASSERT_EQ(pt.getInt("/i"), 1);
      ASSERT_EQ(pt.getInt("i/i"), 2);
      ASSERT_EQ(pt.getInt("/i/i"), 2);
      // Push a namespace on to the stack.
      sm::PropertyTree ipt(pt,"i");
      ASSERT_EQ(ipt.getInt("i"), 2);
      ASSERT_EQ(ipt.getInt("/i"), 1);
      ASSERT_EQ(ipt.getInt("/i/i"), 2);

      ASSERT_EQ(pt.getBool("b"), true);
      ASSERT_EQ(pt.getBool("/b"), true);
      ASSERT_EQ(pt.getBool("b/b"), false);
      ASSERT_EQ(pt.getBool("/b/b"), false);
      // Push a namespace on to the stack.
      sm::PropertyTree bpt(pt,"b");
      ASSERT_EQ(bpt.getBool("b"), false);
      ASSERT_EQ(bpt.getBool("/b"), true);
      ASSERT_EQ(bpt.getBool("/b/b"), false); 

      
      ASSERT_EQ(pt.getString("s"), std::string("hello"));
      ASSERT_EQ(pt.getString("/s"), std::string("hello"));
      ASSERT_EQ(pt.getString("s/s"), std::string("goodbye"));
      ASSERT_EQ(pt.getString("/s/s"), std::string("goodbye"));
      // Push a namespace on to the stack.
      sm::PropertyTree spt(pt,"s");
      ASSERT_EQ(spt.getString("s"), std::string("goodbye"));
      ASSERT_EQ(spt.getString("/s"), std::string("hello"));
      ASSERT_EQ(spt.getString("/s/s"), std::string("goodbye"));

    }
  catch(const std::exception & e)
    {
      FAIL() << "Unhandled exception: " << e.what();
    }
}
