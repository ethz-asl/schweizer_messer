#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, Eigen::Dynamic> test_float_01_D(const Eigen::Matrix<float, 1, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_01_D()
{
	boost::python::def("test_float_01_D",test_float_01_D);
}

