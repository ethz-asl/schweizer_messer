/**
 * @file   omnicam.hpp
 * @author Paul Furgale <paul.furgale@gmail.com>
 * @date   Mon Jan 23 16:54:24 2012
 * 
 * @brief  An implementation of the camera model from 
 * Scaramuzza, D., Martinelli, A. and Siegwart, R., (2006). 
 * "A Toolbox for Easy Calibrating Omnidirectional Cameras", 
 * Proceedings to IEEE International Conference on Intelligent 
 * Robots and Systems (IROS 2006), Beijing China, October 7-15, 2006.
 * 
 * 
 */

#ifndef SM_OMNICAM_HPP
#define SM_OMNICAM_HPP

#include<sm/assert_macros.hpp>

#include <boost/serialization/access.hpp>
// BOOST_SERIALIZATION_NVP
#include <boost/archive/xml_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <Eigen/Dense>


namespace sm { namespace cameras {

    
    class OmniCameraGeometry 
    {
    public:

      SM_DEFINE_EXCEPTION(Exception,std::runtime_error);
    
      OmniCameraGeometry();
      OmniCameraGeometry(const std::vector<double> & _ss,  ///!< The polynomial coefficients
	      const std::vector<double> & _pol, ///!< The inverse polynomial coefficients
	      double _xc, ///!< The image center (horizontal horizontal pixels)
	      double _yc, ///!< The image center (vertical pixels)
	      unsigned int _width,  ///!< image width (pixels)
	      unsigned int _height, ///!< image height (pixels)
	      double _c, ///!< affine transformation parameter c
	      double _d, ///!< affine transformation parameter d
	      double _e  ///!< affine transformation parameter e
	      );

      ~OmniCameraGeometry();

      enum { 
	BoostSerializationVersion = 1 ///!< What is the current version for serialization. 
      };
      enum {
	KeypointDimension = 2 /*!< The dimension of the keypoint associated with this geometry policy */
      };

      ///
      /// \var typedef Eigen::Matrix<double, KeypointDimension, 1> keypoint_t;
      /// The keypoint type associated with this geometry.
      ///
      typedef Eigen::Matrix<double, KeypointDimension, 1> keypoint_t;

      ///
      /// \var typedef Eigen::Matrix<double,4,4> jacobian_homogeneous_t;
      /// The Jacobian that describes how small changes in the components
      /// of a euclidean homogeneous point become changes in a keypoint.
      ///
      typedef Eigen::Matrix<double,KeypointDimension,4> jacobian_homogeneous_t;

      ///
      /// \var typedef Eigen::Matrix<double,KeypointDimension,3> jacobian_t;
      /// The Jacobian that describes how small changes in the components
      /// of a euclidean point become changes in a keypoint.
      ///
      typedef Eigen::Matrix<double,KeypointDimension,3> jacobian_t;

      ///
      /// \var typedef Eigen::Matrix<double,4,KeypointDimension> inverse_jacobian_homogeneous_t
      /// The Jacobian that describes how small changes in keypoint parameters
      /// become changes in a \f$ 4 \times 1 \f$ homogeneous Euclidean point
      ///
      typedef Eigen::Matrix<double,4,KeypointDimension> inverse_jacobian_homogeneous_t;

      ///
      /// \var typedef Eigen::Matrix<double,3,KeypointDimension> inverse_jacobian_t
      /// The Jacobian that describes how small changes in keypoint parameters
      /// become changes in a \f$ 3 \times 1 \f$ Euclidean point
      ///
      typedef Eigen::Matrix<double,3,KeypointDimension> inverse_jacobian_t;

      /** 
       * Convert a keypoint to a Euclidean point
       *
       * @param keypoint 
       * @param outJacobian optional output of the Jacobian of this function with respect to small changes in the keypoint value
       *
       * @return a \f$ 3 \times 1 \f$ unit ray pointing in the direction the keypoint in a local camera coordinate system.
       */
      Eigen::Vector3d keypointToRay( keypoint_t const & keypoint, inverse_jacobian_t * outJacobian = NULL) const;
      Eigen::Vector3d k2r( keypoint_t const & keypoint, inverse_jacobian_t * outJacobian = NULL) const{ return keypointToRay(keypoint,outJacobian); }

      /** 
       * 
       * Produce a keypoint from a \f$ 3 \times 1 \f$ Euclidean point.
       * 
       * @param p a \f$ 3 \times 1 \f$ Euclidean point.
       * @param outJacobian optional output of the Jacobian of this function with respect to small changes in the point
       * 
       * @return the keypoint produced by this point.
       */
      keypoint_t euclideanToKeypoint(Eigen::Vector3d const & p, jacobian_t * outJacobian = NULL) const;
      keypoint_t p2k(Eigen::Vector3d const & p, jacobian_t * outJacobian = NULL) const{ return euclideanToKeypoint(p,outJacobian); }

      /** 
       * 
       * Produce a keypoint from a \f$ 4 \times 1 \f$ Euclidean point.
       * 
       * @param ph a \f$ 4 \times 1 \f$ Euclidean point.
       * @param outJacobian optional output of the Jacobian of this function with respect to small changes in the point
       * 
       * @return the keypoint produced by this point.
       */
      keypoint_t euclideanHomogeneousToKeypoint(Eigen::Vector4d const & ph, jacobian_homogeneous_t * outJacobian = NULL) const;
      keypoint_t ph2k(Eigen::Vector4d const & ph, jacobian_homogeneous_t * outJacobian = NULL) const { return euclideanHomogeneousToKeypoint(ph,outJacobian); }
      
      /** 
       * Transform a keypoint to image coordinates.
       * 
       * @param keypoint The keypoint
       * 
       * @return The image coordinates
       */
      Eigen::Vector2d keypointToImageCoordinates(const keypoint_t & keypoint) const; 


      /** 
       * \todo Should this be more general? Should each geometry define a "window_size_t"? 
       *
       * @param windowSize a number between 0.0 and 1.0 representing the size of the window within the image. 
       *                   0.0 signifies an exact match is required whereas 1.0 means that any pair of keypoints
       *                   be considered.
       * 
       * @return A keypoint representing the window bounds. This can be passed into isPossibleMatch()
       */
      keypoint_t getWindowBounds(float windowSize) const;


      /** 
       * Are these keypoints a possible match given this window size?
       * 
       * @param kp0 
       * @param kp1 
       * @param w    a window bound produced with getWindowBounds()
       *
       * @return True if the pair of keypoints are a possible match within this window size. False otherwise.
       */
      bool isPossibleMatch(keypoint_t const & kp0, keypoint_t const & kp1, keypoint_t const & w) const;
      
      /// 
      /// Return a valid random keypoint. This is used to create generic unit tests for this geometry
      ///
      /// @param seed A seed for the random number generator that makes the random point repeatable.
      ///
      /// @return A valid random keypoint.
      ///
      keypoint_t randomKeypoint(int seed) const;
      
      /// 
      /// A function used for generic component unit testing. This static function returns a
      /// typical valid geometry object.
      ///
      /// @return An initialized geometry object
      ///
      static OmniCameraGeometry createTestGeometry();


      /** 
       * Another function to support testing. Is this geometry binary equivalent to another.
       * 
       * @param rhs The geometry to compare to.
       * 
       * @return true if they are binary equivalent. False otherwise.
       */
      bool isBinaryEqual(const OmniCameraGeometry & rhs) const;


      /// \brief Save the camera structure as a boost binary archive
      void saveBinary(const std::string & fileName);
      /// \brief Load the camera structure from a boost binary archive
      void loadBinary(const std::string & fileName);
      /// \brief Save the camera structure as a boost xml archive
      void saveXml(const std::string & fileName);
      /// \brief Load the camera structure as a boost xml archive
      void loadXml(const std::string & fileName);
      /// \brief Load the camera structure from the output of the OCamCal toolbox
      void loadOCamCal(const std::string & fileName);

      /// The forward polynomial coefficients
      const std::vector<double> & ss() const { return _ss; }
      /// The inverse polynomial coefficients
      const std::vector<double> & pol() const { return _pol; }
      /// The image center (horizontal horizontal pixels)
      double xc() const { return _xc; }
      /// The image center (vertical pixels)
      double yc() const { return _yc; }
      /// image width (pixels)
      unsigned int width() const  { return _width; }
      /// image height (pixels)
      unsigned int height() const { return _height; }
      /// affine transformation parameter c
      double c() const { return _c; }
      /// affine transformation parameter d
      double d() const { return _d; }
      /// affine transformation parameter e
      double e() const { return _e; }

    private:
      /// The forward polynomial coefficients
      std::vector<double> _ss;
      /// The inverse polynomial coefficients
      std::vector<double> _pol;
      /// The image center (horizontal horizontal pixels)
      double _xc;
      /// The image center (vertical pixels)
      double _yc;
      /// image width (pixels)
      unsigned int _width;
      /// image height (pixels)
      unsigned int _height;
      /// affine transformation parameter c
      double _c;
      /// affine transformation parameter d
      double _d;
      /// affine transformation parameter e
      double _e;

      /****************************************
       * Boost Serialization
       ****************************************/
      friend class boost::serialization::access;
      
      template<class Archive>
      void serialize(Archive & ar, const unsigned int version)
      {
	const unsigned int currentVersion = sm::cameras::OmniCameraGeometry::BoostSerializationVersion;
	SM_ASSERT_EQ(Exception, version, currentVersion, "Unknown version number.");
	ar & BOOST_SERIALIZATION_NVP(_ss);
	ar & BOOST_SERIALIZATION_NVP(_pol);
	ar & BOOST_SERIALIZATION_NVP(_xc);
	ar & BOOST_SERIALIZATION_NVP(_yc);
	ar & BOOST_SERIALIZATION_NVP(_width);
	ar & BOOST_SERIALIZATION_NVP(_height);
	ar & BOOST_SERIALIZATION_NVP(_c);
	ar & BOOST_SERIALIZATION_NVP(_d);
	ar & BOOST_SERIALIZATION_NVP(_e);

      }


    };



  }} // namespace sm::cameras

// Needed to have a serialization version
// http://www.boost.org/doc/libs/1_37_0/libs/serialization/doc/traits.html
BOOST_CLASS_VERSION(sm::cameras::OmniCameraGeometry, sm::cameras::OmniCameraGeometry::BoostSerializationVersion)


#endif /* SM_OMNICAM_HPP */
