#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, Eigen::Dynamic> test_double_05_D(const Eigen::Matrix<double, 5, Eigen::Dynamic> & M)
{
	return M;
}
void export_double_05_D()
{
	boost::python::def("test_double_05_D",test_double_05_D);
}

