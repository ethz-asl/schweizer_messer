#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 10> test_float_13_10(const Eigen::Matrix<float, 13, 10> & M)
{
	return M;
}
void export_float_13_10()
{
	boost::python::def("test_float_13_10",test_float_13_10);
}

