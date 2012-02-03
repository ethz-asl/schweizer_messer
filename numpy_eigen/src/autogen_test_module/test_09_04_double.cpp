#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 9, 4> test_double_09_04(const Eigen::Matrix<double, 9, 4> & M)
{
	return M;
}
void export_double_09_04()
{
	boost::python::def("test_double_09_04",test_double_09_04);
}

