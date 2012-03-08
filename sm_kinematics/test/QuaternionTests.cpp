// Bring in gtest
#include <gtest/gtest.h>
#include <boost/cstdint.hpp>

// Helpful functions from libsm
#include <sm/eigen/GTest.hpp>
#include <sm/kinematics/quaternion_algebra.hpp>

TEST(QuaternionAlgebraTestSuite, testRotation)
{
  using namespace sm::kinematics;
  for(int i = 0; i < 1000; i++)
    {
      // Create a random quaternion
      Eigen::Vector4d q_a_b = quatRandom();
      
      // Create a random point in R3
      Eigen::Vector3d v_b;
      v_b.setRandom();
      
      Eigen::Vector3d v_a1 = quat2r(q_a_b) * v_b;
      Eigen::Vector3d v_a2 = quatRotate(q_a_b, v_b);
      
      sm::eigen::assertNear(v_a1, v_a2, 1e-10,SM_SOURCE_FILE_POS, "The rotation matrix And shortcut rotations are not equal");
      
    }
  
}
