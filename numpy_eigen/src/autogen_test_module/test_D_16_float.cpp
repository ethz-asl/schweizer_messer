#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 16> test_float_D_16(const Eigen::Matrix<float, Eigen::Dynamic, 16> & M)
{
	return M;
}
void export_float_D_16()
{
	boost::python::def("test_float_D_16",test_float_D_16);
}

