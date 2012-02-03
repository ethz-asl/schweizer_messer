#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 14> test_double_D_14(const Eigen::Matrix<double, Eigen::Dynamic, 14> & M)
{
	return M;
}
void export_double_D_14()
{
	boost::python::def("test_double_D_14",test_double_D_14);
}

