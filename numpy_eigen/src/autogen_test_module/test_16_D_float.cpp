#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, Eigen::Dynamic> test_float_16_D(const Eigen::Matrix<float, 16, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_16_D()
{
	boost::python::def("test_float_16_D",test_float_16_D);
}

