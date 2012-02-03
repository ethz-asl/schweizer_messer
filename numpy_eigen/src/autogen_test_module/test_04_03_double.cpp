#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 3> test_double_04_03(const Eigen::Matrix<double, 4, 3> & M)
{
	return M;
}
void export_double_04_03()
{
	boost::python::def("test_double_04_03",test_double_04_03);
}

