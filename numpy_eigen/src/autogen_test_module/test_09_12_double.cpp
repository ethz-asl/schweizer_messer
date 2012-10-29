#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 9, 12> test_double_09_12(const Eigen::Matrix<double, 9, 12> & M)
{
	return M;
}
void export_double_09_12()
{
	boost::python::def("test_double_09_12",test_double_09_12);
}

