#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 10> test_float_06_10(const Eigen::Matrix<float, 6, 10> & M)
{
	return M;
}
void export_float_06_10()
{
	boost::python::def("test_float_06_10",test_float_06_10);
}

