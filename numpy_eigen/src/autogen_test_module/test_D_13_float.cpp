#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 13> test_float_D_13(const Eigen::Matrix<float, Eigen::Dynamic, 13> & M)
{
	return M;
}
void export_float_D_13()
{
	boost::python::def("test_float_D_13",test_float_D_13);
}

