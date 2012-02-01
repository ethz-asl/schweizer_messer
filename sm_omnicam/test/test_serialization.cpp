#include <sm/cameras/OmniCameraGeometry.hpp>
#include <ros/package.h>
#include <boost/filesystem.hpp>
// Bring in gtest
#include <gtest/gtest.h>
#include <boost/cstdint.hpp>



TEST(OmniCameraTestSuite, testLoadFile)
{
  boost::filesystem::path pdir = ros::package::getPath("sm_omnicam");
  boost::filesystem::path testDataDirectory = pdir / "test_data";
  ASSERT_TRUE(boost::filesystem::exists(testDataDirectory)) << "Test data directory " << testDataDirectory << " does not exist";
  boost::filesystem::path ocamFile = testDataDirectory / "calib.txt";
    ASSERT_TRUE(boost::filesystem::exists(ocamFile)) << "Sample calibration file " << ocamFile << " does not exist";
  sm::cameras::OmniCameraGeometry ocg;
  ocg.loadOCamCal(ocamFile.string());
}



