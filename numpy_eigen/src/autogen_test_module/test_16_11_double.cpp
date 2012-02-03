#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, 11> test_double_16_11(const Eigen::Matrix<double, 16, 11> & M)
{
	return M;
}
void export_double_16_11()
{
	boost::python::def("test_double_16_11",test_double_16_11);
}

