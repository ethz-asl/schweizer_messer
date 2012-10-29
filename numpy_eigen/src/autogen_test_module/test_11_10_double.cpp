#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 10> test_double_11_10(const Eigen::Matrix<double, 11, 10> & M)
{
	return M;
}
void export_double_11_10()
{
	boost::python::def("test_double_11_10",test_double_11_10);
}

