#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 14> test_float_16_14(const Eigen::Matrix<float, 16, 14> & M)
{
	return M;
}
void export_float_16_14()
{
	boost::python::def("test_float_16_14",test_float_16_14);
}

