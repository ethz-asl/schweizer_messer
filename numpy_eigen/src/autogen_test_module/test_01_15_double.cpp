#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 15> test_double_01_15(const Eigen::Matrix<double, 1, 15> & M)
{
	return M;
}
void export_double_01_15()
{
	boost::python::def("test_double_01_15",test_double_01_15);
}

