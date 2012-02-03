#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 7, 10> test_double_07_10(const Eigen::Matrix<double, 7, 10> & M)
{
	return M;
}
void export_double_07_10()
{
	boost::python::def("test_double_07_10",test_double_07_10);
}

