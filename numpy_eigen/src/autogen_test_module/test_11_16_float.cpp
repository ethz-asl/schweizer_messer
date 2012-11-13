#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 11, 16> test_float_11_16(const Eigen::Matrix<float, 11, 16> & M)
{
	return M;
}
void export_float_11_16()
{
	boost::python::def("test_float_11_16",test_float_11_16);
}

