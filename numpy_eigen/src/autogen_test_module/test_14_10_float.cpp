#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 10> test_float_14_10(const Eigen::Matrix<float, 14, 10> & M)
{
	return M;
}
void export_float_14_10()
{
	boost::python::def("test_float_14_10",test_float_14_10);
}

