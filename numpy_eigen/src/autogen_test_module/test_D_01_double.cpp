#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 1> test_double_D_01(const Eigen::Matrix<double, Eigen::Dynamic, 1> & M)
{
	return M;
}
void export_double_D_01()
{
	boost::python::def("test_double_D_01",test_double_D_01);
}

