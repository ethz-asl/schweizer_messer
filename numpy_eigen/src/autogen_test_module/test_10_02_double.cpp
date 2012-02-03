#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 2> test_double_10_02(const Eigen::Matrix<double, 10, 2> & M)
{
	return M;
}
void export_double_10_02()
{
	boost::python::def("test_double_10_02",test_double_10_02);
}

