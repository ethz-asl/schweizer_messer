#ifndef SM_TRANSFORMATION_HPP
#define SM_TRANSFORMATION_HPP

#include <sm/kinematics/quaternion_algebra.hpp>
#include <boost/serialization/nvp.hpp>

namespace sm {
  namespace kinematics {
    
        ///
    /// @class Transformation
    /// @brief a class that represents a transformation.
    /// @todo describe how these transformations work
    ///
    class Transformation 
    {
    public:
      // See: http://eigen.tuxfamily.org/dox-devel/TopicStructHavingEigenMembers.html
      EIGEN_MAKE_ALIGNED_OPERATOR_NEW

      ///
      /// A 3D Affine transformation (rigid-body translation and rotation).
      ///
      typedef Eigen::Matrix4d transformation_t;
      

      /// 
      /// Default constructor. The transformation and uncertainty will
      /// both be set to identity.
      ///
      Transformation();

      /// 
      /// Constructor. The transformation will be set to T_ab
      ///
      /// @param T_ab the initializing transformation.
      ///
      Transformation(const transformation_t & T_a_b);

      /// 
      /// Constructor. 
      ///
      /// @param q_a_b The quaternion that transforms vectors from b to a
      /// @param t_a_b_a the vector from the origin of frame a, to the origin of frame b, expresessed in frame a.
      ///
      Transformation(const Eigen::Vector4d & q_a_b, const Eigen::Vector3d t_a_b_a);


      /// 
      ///
      /// @return The underlying transformation
      ///
      transformation_t T() const;

      /// @return the rotation matrix
      Eigen::Matrix3d C() const;

      /// @return the translation vector
      Eigen::Vector3d t() const;

      Eigen::Vector4d q() const;

      Eigen::Matrix<double, 3,4> T3x4() const;

      /** 
       * Return a copy of the transformation inverted.
       * 
       * @return The inverted transformation
       */
      Transformation inverse() const;

      // Set this to a random transformation.
      void setRandom();

      
      Transformation operator*(const Transformation & rhs);
      Eigen::Vector3d operator*(const Eigen::Vector3d & rhs);
      Eigen::Vector4d operator*(const Eigen::Vector4d & rhs);

      void checkTransformationIsValid( void ) const;


      /// 
      /// Serialize the Transformation to a boost::serialization archive.
      ///
      /// @param ar The archive
      /// @param version The archive file version number.
      ///
      template<class Archive>
      void serialize(Archive & ar, const unsigned int version);
      
    private:
      
      /// The quaternion that will become a rotation matrix C_a_b that 
      /// transforms vectors from b to a.
      Eigen::Vector4d _q_a_b;

      /// The vector from the origin of a to the origin of b, expressed in a
      Eigen::Vector3d _t_a_b_a;

    };

    
    template<class Archive>
    void Transformation::serialize(Archive & ar, const unsigned int version)
    {
      ar & BOOST_SERIALIZATION_NVP(_q_a_b);
      ar & BOOST_SERIALIZATION_NVP(_t_a_b_a);
    }


  } // namespace kinematics
  
} // namespace sm


#endif /* SM_TRANSFORMATION_HPP */
