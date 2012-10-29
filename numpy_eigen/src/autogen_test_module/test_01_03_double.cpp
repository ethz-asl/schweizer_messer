#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 3> test_double_01_03(const Eigen::Matrix<double, 1, 3> & M)
{
	return M;
}
void export_double_01_03()
{
	boost::python::def("test_double_01_03",test_double_01_03);
}

