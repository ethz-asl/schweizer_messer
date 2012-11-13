#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 11> test_double_11_11(const Eigen::Matrix<double, 11, 11> & M)
{
	return M;
}
void export_double_11_11()
{
	boost::python::def("test_double_11_11",test_double_11_11);
}

