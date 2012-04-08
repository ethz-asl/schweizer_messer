#ifndef SM_HOMOGENEOUS_POINT_HPP
#define SM_HOMOGENEOUS_POINT_HPP

#include <Eigen/Core>
#include <sm/assert_macros.hpp>

namespace sm {
  namespace kinematics {

    class HomogeneousPoint
    {
    public:
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

      SM_DEFINE_EXCEPTION(Exception, std::runtime_error);
      
      typedef Eigen::Matrix3d euclidean_jacobian_t;
      typedef Eigen::Matrix<double,4,3> homogeneous_jacobian_t;

      /// \brief Initialize the point to zero
      HomogeneousPoint();
      /// \brief Initialize the point from a Euclidean point
      HomogeneousPoint(const Eigen::Vector3d & p);
      /// \brief Initialize the point from a Homogeneous point
      HomogeneousPoint(const Eigen::Vector4d & p);
      
      virtual ~HomogeneousPoint();
      
      /// \brief get the Euclidean representation
      Eigen::Vector3d toEuclidean() const;

      /// \brief get the Euclidean representation and the jacobian of the oplus operator with respect to this point. The Jacobian should be 3x3.
      Eigen::Vector3d toEuclideanAndJacobian(euclidean_jacobian_t & J) const;

      /// \brief get the homogeneous representation
      const Eigen::Vector4d & toHomogeneous() const;

      /// \brief get the homogeneous representation and the Jacobian of the oplus operator with respect to this point. The Jacobian should be 3x3.
      const Eigen::Vector4d & toHomogeneousAndJacobian(homogeneous_jacobian_t & J) const;

      /// \brief Add two homogeneous points. 
      /// The result of this operation is the same as adding
      /// the equivelent vectors in R^3
      HomogeneousPoint operator+(const HomogeneousPoint & rhs) const;
      
      /// \brief Subtract one homogeneous point from another. 
      /// The result of this operation is the same as subtracting
      /// the equivelent vectors in R^3
      HomogeneousPoint operator-(const HomogeneousPoint & rhs) const;

      /// \brief Set this point from a 4x1 column
      HomogeneousPoint & operator=(const Eigen::Vector4d & rhs);
      
      /// \brief Set this point from a 3x1 column
      HomogeneousPoint & operator=(const Eigen::Vector3d & rhs);

      /// \brief Implements the "oplus" operator for updating the point from a minimal perturbation
      ///
      /// This oplus operator maps to the \rho(dp)^+ p from quaternion algebra.
      void oplus(const Eigen::Vector3d & dp);

      void setRandom();
 
      /// \brief Normalize the point so that it is unit length
      virtual void normalize();
   protected:
      Eigen::Vector4d _ph;
    };

  } // namespace kinematics
} // namespace sm


#endif /* SM_HOMOGENEOUS_POINT_HPP */
