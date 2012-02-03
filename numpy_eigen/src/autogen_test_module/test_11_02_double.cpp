#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 2> test_double_11_02(const Eigen::Matrix<double, 11, 2> & M)
{
	return M;
}
void export_double_11_02()
{
	boost::python::def("test_double_11_02",test_double_11_02);
}

