#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 15> test_float_D_15(const Eigen::Matrix<float, Eigen::Dynamic, 15> & M)
{
	return M;
}
void export_float_D_15()
{
	boost::python::def("test_float_D_15",test_float_D_15);
}

