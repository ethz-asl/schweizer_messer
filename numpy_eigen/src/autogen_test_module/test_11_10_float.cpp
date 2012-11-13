#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 11, 10> test_float_11_10(const Eigen::Matrix<float, 11, 10> & M)
{
	return M;
}
void export_float_11_10()
{
	boost::python::def("test_float_11_10",test_float_11_10);
}

