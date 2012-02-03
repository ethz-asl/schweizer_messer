#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 13> test_double_11_13(const Eigen::Matrix<double, 11, 13> & M)
{
	return M;
}
void export_double_11_13()
{
	boost::python::def("test_double_11_13",test_double_11_13);
}

