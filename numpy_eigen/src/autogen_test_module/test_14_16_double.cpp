#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, 16> test_double_14_16(const Eigen::Matrix<double, 14, 16> & M)
{
	return M;
}
void export_double_14_16()
{
	boost::python::def("test_double_14_16",test_double_14_16);
}

