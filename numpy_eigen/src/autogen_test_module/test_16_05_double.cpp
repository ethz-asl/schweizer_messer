#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, 5> test_double_16_05(const Eigen::Matrix<double, 16, 5> & M)
{
	return M;
}
void export_double_16_05()
{
	boost::python::def("test_double_16_05",test_double_16_05);
}

