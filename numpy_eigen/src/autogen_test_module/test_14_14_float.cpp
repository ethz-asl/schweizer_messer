#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 14> test_float_14_14(const Eigen::Matrix<float, 14, 14> & M)
{
	return M;
}
void export_float_14_14()
{
	boost::python::def("test_float_14_14",test_float_14_14);
}

