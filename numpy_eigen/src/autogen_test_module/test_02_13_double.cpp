#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 13> test_double_02_13(const Eigen::Matrix<double, 2, 13> & M)
{
	return M;
}
void export_double_02_13()
{
	boost::python::def("test_double_02_13",test_double_02_13);
}

