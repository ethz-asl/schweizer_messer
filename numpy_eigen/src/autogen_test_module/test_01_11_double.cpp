#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 11> test_double_01_11(const Eigen::Matrix<double, 1, 11> & M)
{
	return M;
}
void export_double_01_11()
{
	boost::python::def("test_double_01_11",test_double_01_11);
}

