#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 5> test_double_01_05(const Eigen::Matrix<double, 1, 5> & M)
{
	return M;
}
void export_double_01_05()
{
	boost::python::def("test_double_01_05",test_double_01_05);
}

