#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 11> test_float_D_11(const Eigen::Matrix<float, Eigen::Dynamic, 11> & M)
{
	return M;
}
void export_float_D_11()
{
	boost::python::def("test_float_D_11",test_float_D_11);
}

