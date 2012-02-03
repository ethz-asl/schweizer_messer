#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 12> test_double_D_12(const Eigen::Matrix<double, Eigen::Dynamic, 12> & M)
{
	return M;
}
void export_double_D_12()
{
	boost::python::def("test_double_D_12",test_double_D_12);
}

