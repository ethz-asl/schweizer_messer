#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 12, 5> test_double_12_05(const Eigen::Matrix<double, 12, 5> & M)
{
	return M;
}
void export_double_12_05()
{
	boost::python::def("test_double_12_05",test_double_12_05);
}

