#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 16> test_float_05_16(const Eigen::Matrix<float, 5, 16> & M)
{
	return M;
}
void export_float_05_16()
{
	boost::python::def("test_float_05_16",test_float_05_16);
}

