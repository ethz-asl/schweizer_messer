#ifndef SM_MATH_HOMOGENEOUS_COORDINATES_HPP
#define SM_MATH_HOMOGENEOUS_COORDINATES_HPP

#include <Eigen/Core>

namespace sm { namespace kinematics {

    Eigen::Matrix<double,4,3> toHomogeneousJacobian(const Eigen::Vector3d & v);
    Eigen::Vector4d toHomogeneous(const Eigen::Vector3d & v, Eigen::Matrix<double,4,3> * jacobian = NULL);


    Eigen::Matrix<double,3,4> fromHomogeneousJacobian(const Eigen::Vector4d & v);
    Eigen::Vector3d fromHomogeneous(const Eigen::Vector4d & v, Eigen::Matrix<double,3,4> * jacobian = NULL);


    Eigen::MatrixXd toHomogeneousColumns(const Eigen::MatrixXd & M);
    Eigen::MatrixXd fromHomogeneousColumns(const Eigen::MatrixXd & M);

  }} // namespace sm::kinematics

#endif /* SM_MATH_HOMOGENEOUS_COORDINATES_HPP */
