#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 16> test_double_D_16(const Eigen::Matrix<double, Eigen::Dynamic, 16> & M)
{
	return M;
}
void export_double_D_16()
{
	boost::python::def("test_double_D_16",test_double_D_16);
}

