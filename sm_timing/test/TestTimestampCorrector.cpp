#include <gtest/gtest.h>
#include <sm/timing/TimestampCorrector.hpp>
#include <sm/random.hpp>


TEST(TimestampCorrectorTestSuite, testTimestampCorrector1)
{
  
  try {
    using namespace sm::timing;
    
    TimestampCorrector<double> tc;

    for(int i = 0; i < 1000; ++i)
      {
    	double localTime = i + sm::random::uniform();
    	double remoteTime = i;
	
    	double estLocalTime = tc.correctTimestamp(remoteTime,localTime);
	
    	std::cout << remoteTime << ", " << localTime << ", " << estLocalTime << ", " << tc.convexHullSize() << std::endl;
	
      }

    for(int i = 0; i < 1000; ++i)
      {
    	double remoteTime = i;

    	std::cout << remoteTime << ", " << tc.getLocalTime(remoteTime) << std::endl;
      }

  }
  catch(const std::exception & e)
    {
      FAIL() << e.what();
    }
  
}


TEST(TimestampCorrectorTestSuite, testTimestampCorrectorPeriodic)
{

  try {
    using namespace sm::timing;

    TimestampCorrector<double> tc;
    double switchingPeriod = 100.0;

    for(int i = 0; i < 1000; ++i)
      {
      double localTime = i > 500 ? 1.2*i : i + sm::random::uniform();
      double remoteTime = i;

      double estLocalTime = tc.correctTimestamp(remoteTime, localTime, switchingPeriod);

      if (i % int(switchingPeriod) == 0)
      {
        ASSERT_NEAR(localTime, estLocalTime, 1);
      }

      }

  }
  catch(const std::exception & e)
    {
      FAIL() << e.what();
    }

}


