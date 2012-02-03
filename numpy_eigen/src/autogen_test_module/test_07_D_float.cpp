#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, Eigen::Dynamic> test_float_07_D(const Eigen::Matrix<float, 7, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_07_D()
{
	boost::python::def("test_float_07_D",test_float_07_D);
}

