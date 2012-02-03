#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 5> test_double_05_05(const Eigen::Matrix<double, 5, 5> & M)
{
	return M;
}
void export_double_05_05()
{
	boost::python::def("test_double_05_05",test_double_05_05);
}

