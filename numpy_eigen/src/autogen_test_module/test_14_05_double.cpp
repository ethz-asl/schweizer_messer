#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, 5> test_double_14_05(const Eigen::Matrix<double, 14, 5> & M)
{
	return M;
}
void export_double_14_05()
{
	boost::python::def("test_double_14_05",test_double_14_05);
}

