#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 15> test_double_05_15(const Eigen::Matrix<double, 5, 15> & M)
{
	return M;
}
void export_double_05_15()
{
	boost::python::def("test_double_05_15",test_double_05_15);
}

