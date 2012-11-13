#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 12> test_float_D_12(const Eigen::Matrix<float, Eigen::Dynamic, 12> & M)
{
	return M;
}
void export_float_D_12()
{
	boost::python::def("test_float_D_12",test_float_D_12);
}

