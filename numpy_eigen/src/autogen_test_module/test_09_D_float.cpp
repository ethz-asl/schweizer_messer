#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, Eigen::Dynamic> test_float_09_D(const Eigen::Matrix<float, 9, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_09_D()
{
	boost::python::def("test_float_09_D",test_float_09_D);
}

