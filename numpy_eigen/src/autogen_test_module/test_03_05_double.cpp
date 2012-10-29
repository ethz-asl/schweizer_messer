#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 3, 5> test_double_03_05(const Eigen::Matrix<double, 3, 5> & M)
{
	return M;
}
void export_double_03_05()
{
	boost::python::def("test_double_03_05",test_double_03_05);
}

