#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, 11> test_double_14_11(const Eigen::Matrix<double, 14, 11> & M)
{
	return M;
}
void export_double_14_11()
{
	boost::python::def("test_double_14_11",test_double_14_11);
}

