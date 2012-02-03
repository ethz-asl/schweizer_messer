#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 10> test_float_09_10(const Eigen::Matrix<float, 9, 10> & M)
{
	return M;
}
void export_float_09_10()
{
	boost::python::def("test_float_09_10",test_float_09_10);
}

