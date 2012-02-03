#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 14> test_float_D_14(const Eigen::Matrix<float, Eigen::Dynamic, 14> & M)
{
	return M;
}
void export_float_D_14()
{
	boost::python::def("test_float_D_14",test_float_D_14);
}

