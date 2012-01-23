#include<sm/cameras/OmniCameraGeometry.hpp>

namespace sm { namespace cameras {


    OmniCameraGeometry::OmniCameraGeometry()
    {
      // 0
    }

    OmniCameraGeometry::OmniCameraGeometry(const std::vector<double> & ss,  ///!< The polynomial coefficients
		       const std::vector<double> & pol, ///!< The inverse polynomial coefficients
		       double xc, ///!< The image center (horizontal horizontal pixels)
		       double yc, ///!< The image center (vertical pixels)
		       unsigned int width,  ///!< image width (pixels)
		       unsigned int height, ///!< image height (pixels)
		       double c, ///!< affine transformation parameter c
		       double d, ///!< affine transformation parameter d
		       double e  ///!< affine transformation parameter e
		       )
      : _ss(ss), _pol(pol), _xc(xc), _yc(yc), _width(width), _height(height), _c(c), _d(d), _e(e)
    {
      // 0
    }

    OmniCameraGeometry::~OmniCameraGeometry()
    {
	
    }


    Eigen::Vector3d OmniCameraGeometry::keypointToRay( keypoint_t const & keypoint, inverse_jacobian_t * outJacobian) const
    {
      return Eigen::Vector3d();
    }


    /** 
     * 
     * Produce a keypoint from a \f$ 3 \times 1 \f$ Euclidean point.
     * 
     * @param p a \f$ 3 \times 1 \f$ Euclidean point.
     * @param outJacobian optional output of the Jacobian of this function with respect to small changes in the point
     * 
     * @return the keypoint produced by this point.
     */
    OmniCameraGeometry::keypoint_t OmniCameraGeometry::euclideanToKeypoint(Eigen::Vector3d const & p, jacobian_t * outJacobian) const
    {
      return keypoint_t();
    }


    /** 
     * 
     * Produce a keypoint from a \f$ 4 \times 1 \f$ Euclidean point.
     * 
     * @param ph a \f$ 4 \times 1 \f$ Euclidean point.
     * @param outJacobian optional output of the Jacobian of this function with respect to small changes in the point
     * 
     * @return the keypoint produced by this point.
     */
    OmniCameraGeometry::keypoint_t OmniCameraGeometry::euclideanHomogeneousToKeypoint(Eigen::Vector4d const & ph, jacobian_homogeneous_t * outJacobian) const
    {
      
      return ;
    }

      
    /** 
     * Transform a keypoint to image coordinates.
     * 
     * @param keypoint The keypoint
     * 
     * @return The image coordinates
     */
    Eigen::Vector2d OmniCameraGeometry::keypointToImageCoordinates(const keypoint_t & keypoint) const
    {
      return keypoint;
    }
 


    /** 
     * \todo Should this be more general? Should each geometry define a "window_size_t"? 
     *
     * @param windowSize a number between 0.0 and 1.0 representing the size of the window within the image. 
     *                   0.0 signifies an exact match is required whereas 1.0 means that any pair of keypoints
     *                   be considered.
     * 
     * @return A keypoint representing the window bounds. This can be passed into isPossibleMatch()
     */
    OmniCameraGeometry::keypoint_t OmniCameraGeometry::getWindowBounds(float windowSize) const
    {
      return keypoint_t();
    }



    /** 
     * Are these keypoints a possible match given this window size?
     * 
     * @param kp0 
     * @param kp1 
     * @param w    a window bound produced with getWindowBounds()
     *
     * @return True if the pair of keypoints are a possible match within this window size. False otherwise.
     */
    bool OmniCameraGeometry::isPossibleMatch(keypoint_t const & kp0, keypoint_t const & kp1, keypoint_t const & w) const
    {
      return false;
    }

      
    /// 
    /// Return a valid random keypoint. This is used to create generic unit tests for this geometry
    ///
    /// @param seed A seed for the random number generator that makes the random point repeatable.
    ///
    /// @return A valid random keypoint.
    ///
    OmniCameraGeometry::keypoint_t OmniCameraGeometry::randomKeypoint(int seed) const
    {
      return keypoint_t();
    }

      
    /// 
    /// A function used for generic component unit testing. This static function returns a
    /// typical valid geometry object.
    ///
    /// @return An initialized geometry object
    ///
    OmniCameraGeometry OmniCameraGeometry::createTestGeometry()
    {
      return OmniCameraGeometry();
    }



    /** 
     * Another function to support testing. Is this geometry binary equivalent to another.
     * 
     * @param rhs The geometry to compare to.
     * 
     * @return true if they are binary equivalent. False otherwise.
     */
    bool OmniCameraGeometry::isBinaryEqual(const OmniCameraGeometry & rhs) const
    {
      return false;
    }



    /// \brief Save the camera structure as a boost binary archive
    void OmniCameraGeometry::saveBinary(const std::string & fileName)
    {
      
    }

    /// \brief Load the camera structure from a boost binary archive
    void OmniCameraGeometry::loadBinary(const std::string & fileName)
    {

    }

    /// \brief Save the camera structure as a boost xml archive
    void OmniCameraGeometry::saveXml(const std::string & fileName)
    {

    }

    /// \brief Load the camera structure as a boost xml archive
    void OmniCameraGeometry::loadXml(const std::string & fileName)
    {

    }

    /// \brief Load the camera structure from the output of the OCamCal toolbox
    void OmniCameraGeometry::loadOCamCal(const std::string & fileName)
    {

    }


    

  }} // namespace sm::cameras
