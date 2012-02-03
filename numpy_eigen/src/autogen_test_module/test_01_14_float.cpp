#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, 14> test_float_01_14(const Eigen::Matrix<float, 1, 14> & M)
{
	return M;
}
void export_float_01_14()
{
	boost::python::def("test_float_01_14",test_float_01_14);
}

