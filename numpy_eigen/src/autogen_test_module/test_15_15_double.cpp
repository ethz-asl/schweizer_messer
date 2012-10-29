#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 15, 15> test_double_15_15(const Eigen::Matrix<double, 15, 15> & M)
{
	return M;
}
void export_double_15_15()
{
	boost::python::def("test_double_15_15",test_double_15_15);
}

