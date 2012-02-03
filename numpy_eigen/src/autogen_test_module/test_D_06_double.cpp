#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 6> test_double_D_06(const Eigen::Matrix<double, Eigen::Dynamic, 6> & M)
{
	return M;
}
void export_double_D_06()
{
	boost::python::def("test_double_D_06",test_double_D_06);
}

