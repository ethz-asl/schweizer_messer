#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 5> test_double_10_05(const Eigen::Matrix<double, 10, 5> & M)
{
	return M;
}
void export_double_10_05()
{
	boost::python::def("test_double_10_05",test_double_10_05);
}

