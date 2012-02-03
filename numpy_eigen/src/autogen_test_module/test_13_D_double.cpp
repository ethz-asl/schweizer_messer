#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, Eigen::Dynamic> test_double_13_D(const Eigen::Matrix<double, 13, Eigen::Dynamic> & M)
{
	return M;
}
void export_double_13_D()
{
	boost::python::def("test_double_13_D",test_double_13_D);
}

