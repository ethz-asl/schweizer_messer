#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 16> test_float_10_16(const Eigen::Matrix<float, 10, 16> & M)
{
	return M;
}
void export_float_10_16()
{
	boost::python::def("test_float_10_16",test_float_10_16);
}

