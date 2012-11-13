#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 11> test_double_D_11(const Eigen::Matrix<double, Eigen::Dynamic, 11> & M)
{
	return M;
}
void export_double_D_11()
{
	boost::python::def("test_double_D_11",test_double_D_11);
}

