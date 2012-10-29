#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, 16> test_float_01_16(const Eigen::Matrix<float, 1, 16> & M)
{
	return M;
}
void export_float_01_16()
{
	boost::python::def("test_float_01_16",test_float_01_16);
}

