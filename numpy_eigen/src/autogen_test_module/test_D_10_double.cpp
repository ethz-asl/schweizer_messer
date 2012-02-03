#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 10> test_double_D_10(const Eigen::Matrix<double, Eigen::Dynamic, 10> & M)
{
	return M;
}
void export_double_D_10()
{
	boost::python::def("test_double_D_10",test_double_D_10);
}

