#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, Eigen::Dynamic> test_double_16_D(const Eigen::Matrix<double, 16, Eigen::Dynamic> & M)
{
	return M;
}
void export_double_16_D()
{
	boost::python::def("test_double_16_D",test_double_16_D);
}

