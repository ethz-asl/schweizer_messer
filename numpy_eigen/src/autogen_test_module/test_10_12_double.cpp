#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 12> test_double_10_12(const Eigen::Matrix<double, 10, 12> & M)
{
	return M;
}
void export_double_10_12()
{
	boost::python::def("test_double_10_12",test_double_10_12);
}

