#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 12, 6> test_double_12_06(const Eigen::Matrix<double, 12, 6> & M)
{
	return M;
}
void export_double_12_06()
{
	boost::python::def("test_double_12_06",test_double_12_06);
}

