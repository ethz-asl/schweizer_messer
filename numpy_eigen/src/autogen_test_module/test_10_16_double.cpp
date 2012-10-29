#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 16> test_double_10_16(const Eigen::Matrix<double, 10, 16> & M)
{
	return M;
}
void export_double_10_16()
{
	boost::python::def("test_double_10_16",test_double_10_16);
}

