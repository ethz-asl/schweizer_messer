#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 16> test_float_14_16(const Eigen::Matrix<float, 14, 16> & M)
{
	return M;
}
void export_float_14_16()
{
	boost::python::def("test_float_14_16",test_float_14_16);
}

