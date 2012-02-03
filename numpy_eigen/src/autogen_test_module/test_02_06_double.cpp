#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 6> test_double_02_06(const Eigen::Matrix<double, 2, 6> & M)
{
	return M;
}
void export_double_02_06()
{
	boost::python::def("test_double_02_06",test_double_02_06);
}

