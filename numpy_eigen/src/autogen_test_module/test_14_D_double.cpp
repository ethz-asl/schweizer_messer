#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, Eigen::Dynamic> test_double_14_D(const Eigen::Matrix<double, 14, Eigen::Dynamic> & M)
{
	return M;
}
void export_double_14_D()
{
	boost::python::def("test_double_14_D",test_double_14_D);
}

