#ifndef SM_ROTATIONAL_KINEMATICS_EXYZ_HPP
#define SM_ROTATIONAL_KINEMATICS_EXYZ_HPP

#include "RotationalKinematics.hpp"

namespace sm { namespace kinematics {
    
    class EulerAnglesZYX : public RotationalKinematics
    {
    public:
      ~EulerAnglesZYX() override;
      // Three functions that must be implemented.
      Eigen::Matrix3d parametersToRotationMatrix(const Eigen::Vector3d & parameters, Eigen::Matrix3d * S = NULL) const override;
      Eigen::Vector3d rotationMatrixToParameters(const Eigen::Matrix3d & rotationMatrix) const override;
      Eigen::Matrix3d parametersToSMatrix(const Eigen::Vector3d & parameters) const override;
      Eigen::Vector3d angularVelocityAndJacobian(const Eigen::Vector3d & p, const Eigen::Vector3d & pdot, Eigen::Matrix<double,3,6> * Jacobian) const override;
    
    private:
      // A helper function
      Eigen::Matrix3d buildSMatrix(double sz, double cz, double sy, double cy) const;
    };

  }} // namespace sm::kinematics


#endif 
