#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, 2> test_double_16_02(const Eigen::Matrix<double, 16, 2> & M)
{
	return M;
}
void export_double_16_02()
{
	boost::python::def("test_double_16_02",test_double_16_02);
}

