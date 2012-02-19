#ifndef SM_NUMERICAL_DIFF_HPP
#define SM_NUMERICAL_DIFF_HPP

#include <Eigen/Core>
#include <sm/assert_macros.hpp>

namespace sm { namespace eigen {

    
    struct AddUpdatePolicy
    {
      template<typename T>
      T update(T input, int dim, double delta)
      {
	input[dim] += delta;
	return input;
      }
    };

    // A simple implementation of central differences to estimate a Jacobian matrix
    template<typename FUNCTOR_T, typename UPDATE_POLICY_T = AddUpdatePolicy>
    struct NumericalDiff
    {
      typedef FUNCTOR_T functor_t;
      typedef typename functor_t::input_t input_t;
      typedef typename functor_t::jacobian_t jacobian_t;
      typedef typename functor_t::value_t value_t;
      typedef typename functor_t::scalar_t scalar_t;
      typedef UPDATE_POLICY_T update_policy_t;

      NumericalDiff(functor_t f, scalar_t eps = sqrt(std::numeric_limits<scalar_t>::epsilon())) : functor(f), eps(eps) {}
      
      jacobian_t estimateJacobian(input_t const & x0)
      {
	// evaluate the function at the operating point:
	value_t fx0 = functor(x0);
	size_t N = x0.size();
	size_t M = fx0.size();
	
	//std::cout << "Size: " << M << ", " << N << std::endl;
	jacobian_t J;
	if(jacobian_t::RowsAtCompileTime == Eigen::Dynamic || jacobian_t::ColsAtCompileTime == Eigen::Dynamic)
	  {
	    J.resize(M, N);
	  }
	SM_ASSERT_EQ(std::runtime_error,x0.size(),J.cols(),"Unexpected number of columns for input size");
	SM_ASSERT_EQ(std::runtime_error,fx0.size(),J.rows(),"Unexpected number of columns for output size");	

	for(unsigned c = 0; c < N; c++) {
	  // Calculate a central difference.
	  // This step size was stolen from cminpack: temp = eps * fabs(x[j]);
	  scalar_t rcEps = std::max(fabs(x0(c)) * eps,eps);
			
	  //input_t x(x0);
	  //scalar_t xc = x(c);
	  //x(c) = xc + rcEps;
	  value_t fxp = functor(updator.update(x0,c,rcEps));
	  //x(c) = xc - rcEps;
	  value_t fxm = functor(updator.update(x0,c,-rcEps));
	  value_t dfx = (fxp - fxm)/(rcEps*(scalar_t)2.0);
	  
	  for(unsigned r = 0; r < M; r++) {
	    J(r,c) = dfx(r);
	  }
	}
	return J;
      }

      functor_t functor;
      scalar_t eps;
      update_policy_t updator;
    };

  }}


#endif /* SM_NUMERICAL_DIFF_HPP */



