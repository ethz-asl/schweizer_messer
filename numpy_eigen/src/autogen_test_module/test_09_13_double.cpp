#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 9, 13> test_double_09_13(const Eigen::Matrix<double, 9, 13> & M)
{
	return M;
}
void export_double_09_13()
{
	boost::python::def("test_double_09_13",test_double_09_13);
}

