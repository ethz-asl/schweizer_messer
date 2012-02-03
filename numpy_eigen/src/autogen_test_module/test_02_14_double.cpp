#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 14> test_double_02_14(const Eigen::Matrix<double, 2, 14> & M)
{
	return M;
}
void export_double_02_14()
{
	boost::python::def("test_double_02_14",test_double_02_14);
}

