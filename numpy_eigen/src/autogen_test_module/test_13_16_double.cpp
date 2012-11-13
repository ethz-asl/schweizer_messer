#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 16> test_double_13_16(const Eigen::Matrix<double, 13, 16> & M)
{
	return M;
}
void export_double_13_16()
{
	boost::python::def("test_double_13_16",test_double_13_16);
}

