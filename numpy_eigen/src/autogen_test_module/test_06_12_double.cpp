#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 6, 12> test_double_06_12(const Eigen::Matrix<double, 6, 12> & M)
{
	return M;
}
void export_double_06_12()
{
	boost::python::def("test_double_06_12",test_double_06_12);
}

