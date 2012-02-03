#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 4> test_double_D_04(const Eigen::Matrix<double, Eigen::Dynamic, 4> & M)
{
	return M;
}
void export_double_D_04()
{
	boost::python::def("test_double_D_04",test_double_D_04);
}

