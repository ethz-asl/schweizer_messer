#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 16> test_double_04_16(const Eigen::Matrix<double, 4, 16> & M)
{
	return M;
}
void export_double_04_16()
{
	boost::python::def("test_double_04_16",test_double_04_16);
}

