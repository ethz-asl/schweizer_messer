#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 16> test_float_16_16(const Eigen::Matrix<float, 16, 16> & M)
{
	return M;
}
void export_float_16_16()
{
	boost::python::def("test_float_16_16",test_float_16_16);
}

