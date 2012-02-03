#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 15> test_double_11_15(const Eigen::Matrix<double, 11, 15> & M)
{
	return M;
}
void export_double_11_15()
{
	boost::python::def("test_double_11_15",test_double_11_15);
}

