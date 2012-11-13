#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 14> test_double_11_14(const Eigen::Matrix<double, 11, 14> & M)
{
	return M;
}
void export_double_11_14()
{
	boost::python::def("test_double_11_14",test_double_11_14);
}

