#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, 10> test_double_16_10(const Eigen::Matrix<double, 16, 10> & M)
{
	return M;
}
void export_double_16_10()
{
	boost::python::def("test_double_16_10",test_double_16_10);
}

