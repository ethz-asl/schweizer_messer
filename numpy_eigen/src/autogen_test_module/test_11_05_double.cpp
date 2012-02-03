#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 5> test_double_11_05(const Eigen::Matrix<double, 11, 5> & M)
{
	return M;
}
void export_double_11_05()
{
	boost::python::def("test_double_11_05",test_double_11_05);
}

