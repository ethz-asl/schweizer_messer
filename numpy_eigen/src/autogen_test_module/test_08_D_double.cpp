#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 8, Eigen::Dynamic> test_double_08_D(const Eigen::Matrix<double, 8, Eigen::Dynamic> & M)
{
	return M;
}
void export_double_08_D()
{
	boost::python::def("test_double_08_D",test_double_08_D);
}

