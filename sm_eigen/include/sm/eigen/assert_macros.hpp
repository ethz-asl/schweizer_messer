#ifndef ASRL_EIGEN_ISNAN_HPP
#define ASRL_EIGEN_ISNAN_HPP

#include <cmath>
#include "../assert_macros.hpp"


#define ASRL_ASSERT_MAT_IS_FINITE(exceptionType, matrix, message)		\
  {									\
  for(int r = 0; r < matrix.rows(); ++r)				\
    {									\
      for(int c = 0; c < matrix.cols(); ++c)				\
	{								\
	  if(!std::isfinite(matrix(r,c)))				\
	    {								\
	      std::stringstream asrl_assert_stringstream;		\
	      asrl_assert_stringstream << "debug assert( isfinite(" << #matrix << "(" << r << ", " << c << ") ) failed. [ isfinite(" << matrix(r,c) << " ) ]" << message << std::endl << matrix; \
	      asrl::detail::throw_exception<exceptionType>("[" #exceptionType "] ", __FUNCTION__,__FILE__,__LINE__,asrl_assert_stringstream.str()); \
	    }								\
	}								\
     }   								\
}


#ifndef NDEBUG

#define ASRL_ASSERT_MAT_IS_FINITE_DBG(exceptionType, matrix, message)		\
  {									\
  for(int r = 0; r < matrix.rows(); ++r)				\
    {									\
      for(int c = 0; c < matrix.cols(); ++c)				\
	{								\
	  if(!std::isfinite(matrix(r,c)))				\
	    {								\
	      std::stringstream asrl_assert_stringstream;		\
	      asrl_assert_stringstream << "assert( isfinite(" << #matrix << "(" << r << ", " << c << ") ) failed. [ isfinite(" << matrix(r,c) << " ) ]" << message << std::endl << matrix; \
	      asrl::detail::throw_exception<exceptionType>("[" #exceptionType "] ", __FUNCTION__,__FILE__,__LINE__,asrl_assert_stringstream.str()); \
	    }								\
	}								\
     }   								\
}


#else

#define ASRL_ASSERT_MAT_IS_FINITE_DBG(exceptionType, matrix, message)

#endif


#endif /* ASRL_EIGEN_ISNAN_HPP */
