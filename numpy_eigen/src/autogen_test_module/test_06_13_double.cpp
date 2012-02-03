#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 6, 13> test_double_06_13(const Eigen::Matrix<double, 6, 13> & M)
{
	return M;
}
void export_double_06_13()
{
	boost::python::def("test_double_06_13",test_double_06_13);
}

