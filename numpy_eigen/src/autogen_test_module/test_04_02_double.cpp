#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 2> test_double_04_02(const Eigen::Matrix<double, 4, 2> & M)
{
	return M;
}
void export_double_04_02()
{
	boost::python::def("test_double_04_02",test_double_04_02);
}

