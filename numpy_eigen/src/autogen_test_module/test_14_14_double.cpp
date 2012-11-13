#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, 14> test_double_14_14(const Eigen::Matrix<double, 14, 14> & M)
{
	return M;
}
void export_double_14_14()
{
	boost::python::def("test_double_14_14",test_double_14_14);
}

