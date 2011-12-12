///
/// @file   EigenSerialization.hpp
/// @author Paul Furgale <paul.furgale@utoronto.ca>
/// @date   Tue Oct 26 12:57:31 2010
/// 
/// @brief  Functions to serialize dense Eigen matrices.
/// 
/// 
///


#ifndef ASRL_EIGEN_SERIALIZATION_HPP
#define ASRL_EIGEN_SERIALIZATION_HPP

#include <Eigen/Core>
#include <asrl/assert_macros.hpp>
#include <boost/serialization/split_free.hpp>


namespace boost { namespace serialization {


    /// 
    /// boost::serialization helper function for the Eigen3 Matrix object.
    /// The matrix is a base class for dense matrices.
    /// http://eigen.tuxfamily.org/dox-devel/TutorialMatrixClass.html
    ///
    /// This function should not be called directly but will be called
    /// when serializing a matrix.
    ///
    ///
    /// @param ar  The boost::serialization archive
    /// @param M   The matrix to serialize
    /// @param file_version The file version to be serialized.
    ///  
    template<class Archive, class Scalar, int A, int B, int C, int D, int E>
    inline void save( Archive & ar, 
		      const Eigen::Matrix<Scalar,A,B,C,D,E> & M, 
		      const unsigned int file_version)
    {
      int rows = M.rows();
      int cols = M.cols();
      ar << rows;
      ar << cols;

      ar << make_array(&M(0,0),M.rows()*M.cols());
    }


    /// 
    /// Loads an Eigen3 matrix object from a boost::serialization archive.
    /// This function has several specializations to handle Matrices with
    /// fixed sizes and those with dynamic sizes. This function is called
    /// by the boost serialization code and should not be called directly.
    ///
    /// This specialization handles fixed sized matrices
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The matrix to be loaded
    /// @param file_version The archive version number.
    ///
    template<class Archive, class Scalar, int A, int B, int C, int D, int E>
    inline void load( Archive & ar, 
		      Eigen::Matrix<Scalar,A,B,C,D,E> & M,
		      const unsigned int file_version)
    {
      int rows, cols;
      ar >> rows;
      ar >> cols;
      ASRL_ASSERT_EQ(std::runtime_error,rows,A,"Unexpected number of rows found for fixed-sized type");
      ASRL_ASSERT_EQ(std::runtime_error,cols,B,"Unexpected number of columns found for fixed-sized type");

      if(rows > 0 && cols > 0)
	{
	  ar >> make_array(&M(0,0),M.rows()*M.cols());
	}
    }


    /// 
    /// Loads an Eigen3 matrix object from a boost::serialization archive.
    /// This function has several specializations to handle Matrices with
    /// fixed sizes and those with dynamic sizes. This function is called
    /// by the boost serialization code and should not be called directly.
    ///
    /// This specialization handles dynamically-sized sized column vectors
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The matrix to be loaded
    /// @param file_version The archive version number.
    ///
    template<class Archive, class Scalar, int B, int C, int D, int E>
    inline void load( Archive & ar, 
		      Eigen::Matrix<Scalar,Eigen::Dynamic,B,C,D,E> & M,
		      const unsigned int file_version)
    {

      int rows, cols;
      ar >> rows;
      ar >> cols;
      ASRL_ASSERT_EQ(std::runtime_error,cols,B,"Unexpected number of columns found for fixed-sized type");
      
      M.resize(rows,Eigen::NoChange);
      if(rows > 0 && cols > 0)
	{
	  ar >> make_array(&M(0,0),M.rows()*M.cols());
	}
    }

    /// 
    /// Loads an Eigen3 matrix object from a boost::serialization archive.
    /// This function has several specializations to handle Matrices with
    /// fixed sizes and those with dynamic sizes. This function is called
    /// by the boost serialization code and should not be called directly.
    ///
    /// This specialization handles dynamically sized row vectors
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The matrix to be loaded
    /// @param file_version The archive version number.
    ///
    template<class Archive, class Scalar, int A, int C, int D, int E>
    inline void load( Archive & ar, 
		      Eigen::Matrix<Scalar,A,Eigen::Dynamic,C,D,E> & M,
		      const unsigned int file_version)
    {

      int rows, cols;
      ar >> rows;
      ar >> cols;
      ASRL_ASSERT_EQ(std::runtime_error,rows,A,"Unexpected number of rows found for fixed-sized type");
    
      M.resize(Eigen::NoChange,cols);
      ar >> make_array(&M(0,0),M.rows()*M.cols());

    }

    /// 
    /// Loads an Eigen3 matrix object from a boost::serialization archive.
    /// This function has several specializations to handle Matrices with
    /// fixed sizes and those with dynamic sizes. This function is called
    /// by the boost serialization code and should not be called directly.
    ///
    /// This specialization handles dynamically sized matrices
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The matrix to be loaded
    /// @param file_version The archive version number.
    ///
    template<class Archive, class Scalar, int C, int D, int E>
    inline void load( Archive & ar, 
		      Eigen::Matrix<Scalar,Eigen::Dynamic,Eigen::Dynamic,C,D,E> & M,
		      const unsigned int file_version)
    {
      int rows, cols;
      ar >> rows;
      ar >> cols;    
      
      M.resize(rows,cols);
      if(rows > 0 && cols > 0)
	{
	  ar >> make_array(&M(0,0),M.rows()*M.cols());
	}
    }


    /// 
    /// The function that causes boost::serialization to look for
    /// seperate save() and load() functions when serializing
    /// and Eigen3 matrix.
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The matrix to be serialized
    /// @param file_version The archive version number.
    ///
    template<class Archive, class Scalar, int A, int B, int C, int D, int E>
    inline void serialize(
			  Archive & ar,
			  Eigen::Matrix<Scalar,A,B,C,D,E> & M,
			  const unsigned int file_version
			  ){
      boost::serialization::split_free(ar, M, file_version);
    }


    /// 
    /// A function that serialized an Eigen3 Transform by causing the underlying
    /// Eigen3 matrix to be serialized.
    ///
    /// @param ar The boost::serialization archive
    /// @param M  The transform to be serialized
    /// @param file_version The archive version number. 
    ///
    template<class Archive, class Scalar, int Dim, int Mode>
     inline void serialize( Archive & ar, 
			    Eigen::Transform<Scalar, Dim, Mode> & M, 
			    const unsigned int file_version )
     {
       
       ar & M.matrix();
     }


}}

#endif // ASRL_EIGEN_SERIALIZATION_HPP
