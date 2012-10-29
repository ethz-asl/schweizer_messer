#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 11> test_double_10_11(const Eigen::Matrix<double, 10, 11> & M)
{
	return M;
}
void export_double_10_11()
{
	boost::python::def("test_double_10_11",test_double_10_11);
}

