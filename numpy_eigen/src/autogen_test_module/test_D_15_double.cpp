#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 15> test_double_D_15(const Eigen::Matrix<double, Eigen::Dynamic, 15> & M)
{
	return M;
}
void export_double_D_15()
{
	boost::python::def("test_double_D_15",test_double_D_15);
}

