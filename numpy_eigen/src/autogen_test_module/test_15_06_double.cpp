#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 15, 6> test_double_15_06(const Eigen::Matrix<double, 15, 6> & M)
{
	return M;
}
void export_double_15_06()
{
	boost::python::def("test_double_15_06",test_double_15_06);
}

