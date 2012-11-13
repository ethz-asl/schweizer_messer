#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 16> test_float_15_16(const Eigen::Matrix<float, 15, 16> & M)
{
	return M;
}
void export_float_15_16()
{
	boost::python::def("test_float_15_16",test_float_15_16);
}

