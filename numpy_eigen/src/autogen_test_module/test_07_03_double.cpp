#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 7, 3> test_double_07_03(const Eigen::Matrix<double, 7, 3> & M)
{
	return M;
}
void export_double_07_03()
{
	boost::python::def("test_double_07_03",test_double_07_03);
}

