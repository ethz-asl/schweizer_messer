#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 10> test_float_12_10(const Eigen::Matrix<float, 12, 10> & M)
{
	return M;
}
void export_float_12_10()
{
	boost::python::def("test_float_12_10",test_float_12_10);
}

