#ifndef SM_UNCERTAIN_TRANSFORMATION_HPP
#define SM_UNCERTAIN_TRANSFORMATION_HPP

#include "Transformation.hpp"
#include <boost/serialization/base_object.hpp>
#include "UncertainHomogeneousPoint.hpp"

namespace sm {
  namespace kinematics {
    
    class UncertainTransformation : public Transformation
    {
    public:
      typedef Eigen::Matrix<double,6,6> covariance_t;

      /// 
      /// Default constructor. The transformation and uncertainty will
      /// both be set to identity.
      ///
      UncertainTransformation();

      UncertainTransformation(const Eigen::Matrix4d & T, const covariance_t & U);

      UncertainTransformation(const Eigen::Matrix4d & T, double diagonalTranslationVariance, double diagonalRotationVariance);

      UncertainTransformation(const Eigen::Vector4d & q_a_b, const Eigen::Vector3d t_a_b_a, const covariance_t & U);

      UncertainTransformation(const Eigen::Vector4d & q_a_b, const Eigen::Vector3d t_a_b_a, double diagonalTranslationVariance, double diagonalRotationVariance);

      UncertainTransformation(const Transformation & T, const covariance_t & U);

      UncertainTransformation(const Transformation & T, double diagonalTranslationVariance, double diagonalRotationVariance);

      /// \brief Initialize with zero uncertainty
      UncertainTransformation(const Transformation & T);
      /// \brief Initialize with zero uncertainty
      UncertainTransformation(const Eigen::Matrix4d & T);
      /// \brief Initialize with zero uncertainty
      UncertainTransformation(const Eigen::Vector4d & q_a_b, const Eigen::Vector3d t_a_b_a);


      virtual ~UncertainTransformation();
      
      UncertainTransformation operator*(const UncertainTransformation & rhs) const;
      Transformation operator*(const Transformation & rhs) const{ return Transformation::operator*(rhs); }
      Eigen::Vector3d operator*(const Eigen::Vector3d & rhs) const{ return Transformation::operator*(rhs); }
      Eigen::Vector4d operator*(const Eigen::Vector4d & rhs) const{ return Transformation::operator*(rhs); }
      HomogeneousPoint operator*(const HomogeneousPoint & rhs) const{ return Transformation::operator*(rhs); }
      UncertainHomogeneousPoint operator*(const UncertainHomogeneousPoint & rhs) const;

      
      UncertainTransformation inverse() const;

      const covariance_t & U() const;

      /// \brief This sets the uncertainty directly.
      void setU(const covariance_t & U);

      /// \brief This sets the uncertainty based on the "oplus" function for updating the transformation matrix.
      /// This is a different uncertainty than that carried around by the class, so one should be careful. 
      void setUOplus(const covariance_t & oplusU);

      // Set this to a random transformation.
      virtual void setRandom();

      bool isBinaryEqual(const UncertainTransformation & rhs) const;
      
      template<class Archive>
      void serialize(Archive & ar, const unsigned int version);

    private:
      covariance_t _U;
    };

    template<class Archive>
    void UncertainTransformation::serialize(Archive & ar, const unsigned int version)
    {
      ar & boost::serialization::base_object<Transformation>(*this);
      ar & BOOST_SERIALIZATION_NVP(_U);
    }

    
  } // namespace kinematics
} // namespace sm


#endif /* SM_UNCERTAIN_TRANSFORMATION_HPP */
