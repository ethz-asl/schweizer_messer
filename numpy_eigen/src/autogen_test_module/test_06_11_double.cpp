#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 6, 11> test_double_06_11(const Eigen::Matrix<double, 6, 11> & M)
{
	return M;
}
void export_double_06_11()
{
	boost::python::def("test_double_06_11",test_double_06_11);
}

