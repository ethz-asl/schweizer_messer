#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 6> test_double_01_06(const Eigen::Matrix<double, 1, 6> & M)
{
	return M;
}
void export_double_01_06()
{
	boost::python::def("test_double_01_06",test_double_01_06);
}

