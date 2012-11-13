#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 4> test_double_13_04(const Eigen::Matrix<double, 13, 4> & M)
{
	return M;
}
void export_double_13_04()
{
	boost::python::def("test_double_13_04",test_double_13_04);
}

