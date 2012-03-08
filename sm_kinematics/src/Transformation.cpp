#include <sm/kinematics/Transformation.hpp>
#include <sm/kinematics/quaternion_algebra.hpp>

namespace sm {
  namespace kinematics {
    
    
    Transformation::Transformation()
    {
      
    }

    
    Transformation::Transformation(transformation_t const & T_a_b) :
      _q_a_b( r2quat(T_a_b.topLeftCorner<3,3>()) ),
      _t_a_b_a( T_a_b.topRightCorner<3,1>() )
    {

    }

    Transformation::Transformation(const Eigen::Vector4d & q_a_b, const Eigen::Vector3d t_a_b_a) :
      _q_a_b(q_a_b), _t_a_b_a(t_a_b_a)
    {
      
    }

    /// @return the rotation matrix
    Eigen::Matrix3d Transformation::C() const
    {
      return quat2r(_q_a_b);
    }

    /// @return the translation vector
    Eigen::Vector3d Transformation::t() const
    {
      return _t_a_b_a;
    }

    
    Transformation::transformation_t Transformation::T() const
    {
      Eigen::Matrix4d T_a_b;
      // \todo...make this do less copying.
      T_a_b.topLeftCorner<3,3>() = quat2r(_q_a_b);
      T_a_b.topRightCorner<3,1>() = _t_a_b_a;
      T_a_b.bottomLeftCorner<1,3>().setZero();
      T_a_b(3,3) = 1.0;
      return T_a_b;
    }

    Eigen::Matrix<double, 3,4> Transformation::T3x4() const
    {
      Eigen::Matrix<double, 3, 4> T3x4;
      // \todo...make this do less copying.
      T3x4.topLeftCorner<3,3>() = quat2r(_q_a_b);
      T3x4.topRightCorner<3,1>() = _t_a_b_a;
      return T3x4;
    }

    Transformation Transformation::inverse() const
    {      
      // \todo Make this do less copying.
      return Transformation(quatInv(_q_a_b), quatRotate(quatInv(_q_a_b),-_t_a_b_a));
    }

    void Transformation::checkTransformationIsValid( void ) const
    {
      // \todo.
    }


    Transformation Transformation::operator*(const Transformation & rhs)
    {
      return Transformation(qplus(_q_a_b,rhs._q_a_b), quatRotate(_q_a_b,rhs._t_a_b_a) + _t_a_b_a);
    }

    Eigen::Vector3d Transformation::operator*(const Eigen::Vector3d & rhs)
    {
      return quatRotate(_q_a_b, rhs) + _t_a_b_a;
    }

    Eigen::Vector4d Transformation::operator*(const Eigen::Vector4d & rhs)
    {
      Eigen::Vector4d rval;
      rval.head<3>() = quatRotate(_q_a_b, rhs.head<3>()) + rhs[3] * _t_a_b_a;
      rval[3] = rhs[3];
      
      return rval;
      
    }


  } // namespace kinematics
} // namespace sm
