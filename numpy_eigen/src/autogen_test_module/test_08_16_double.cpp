#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 8, 16> test_double_08_16(const Eigen::Matrix<double, 8, 16> & M)
{
	return M;
}
void export_double_08_16()
{
	boost::python::def("test_double_08_16",test_double_08_16);
}

