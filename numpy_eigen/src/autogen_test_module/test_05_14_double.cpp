#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 14> test_double_05_14(const Eigen::Matrix<double, 5, 14> & M)
{
	return M;
}
void export_double_05_14()
{
	boost::python::def("test_double_05_14",test_double_05_14);
}

