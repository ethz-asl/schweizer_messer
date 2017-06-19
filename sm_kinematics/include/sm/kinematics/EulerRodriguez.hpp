#ifndef SM_ROTATIONAL_KINEMATICS_ER_HPP
#define SM_ROTATIONAL_KINEMATICS_ER_HPP

#include "RotationalKinematics.hpp"

namespace sm { namespace kinematics {
    
    class EulerRodriguez : public RotationalKinematics
    {
    public:
      ~EulerRodriguez() override;
      // Three functions that must be implemented.
      Eigen::Matrix3d parametersToRotationMatrix(const Eigen::Vector3d & parameters, Eigen::Matrix3d * S = NULL) const override;
      Eigen::Vector3d rotationMatrixToParameters(const Eigen::Matrix3d & rotationMatrix) const override;
      Eigen::Matrix3d parametersToSMatrix(const Eigen::Vector3d & parameters) const override;
      Eigen::Vector3d angularVelocityAndJacobian(const Eigen::Vector3d & p, const Eigen::Vector3d & pdot, Eigen::Matrix<double,3,6> * Jacobian) const override;    
    };


  }} // namespace sm::kinematics


#endif /* SM_ROTATIONAL_KINEMATICS_HPP */
