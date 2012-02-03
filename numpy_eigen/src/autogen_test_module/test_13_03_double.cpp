#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 3> test_double_13_03(const Eigen::Matrix<double, 13, 3> & M)
{
	return M;
}
void export_double_13_03()
{
	boost::python::def("test_double_13_03",test_double_13_03);
}

