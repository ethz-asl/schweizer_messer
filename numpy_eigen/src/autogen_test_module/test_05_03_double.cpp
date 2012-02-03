#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 3> test_double_05_03(const Eigen::Matrix<double, 5, 3> & M)
{
	return M;
}
void export_double_05_03()
{
	boost::python::def("test_double_05_03",test_double_05_03);
}

