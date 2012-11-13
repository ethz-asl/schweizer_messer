#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 14> test_float_06_14(const Eigen::Matrix<float, 6, 14> & M)
{
	return M;
}
void export_float_06_14()
{
	boost::python::def("test_float_06_14",test_float_06_14);
}

