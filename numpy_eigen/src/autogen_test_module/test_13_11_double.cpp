#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 11> test_double_13_11(const Eigen::Matrix<double, 13, 11> & M)
{
	return M;
}
void export_double_13_11()
{
	boost::python::def("test_double_13_11",test_double_13_11);
}

