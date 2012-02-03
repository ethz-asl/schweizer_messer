#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 7, 5> test_double_07_05(const Eigen::Matrix<double, 7, 5> & M)
{
	return M;
}
void export_double_07_05()
{
	boost::python::def("test_double_07_05",test_double_07_05);
}

