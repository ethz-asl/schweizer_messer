#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 6> test_double_11_06(const Eigen::Matrix<double, 11, 6> & M)
{
	return M;
}
void export_double_11_06()
{
	boost::python::def("test_double_11_06",test_double_11_06);
}

