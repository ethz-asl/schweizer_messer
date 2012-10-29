#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 10> test_float_10_10(const Eigen::Matrix<float, 10, 10> & M)
{
	return M;
}
void export_float_10_10()
{
	boost::python::def("test_float_10_10",test_float_10_10);
}

