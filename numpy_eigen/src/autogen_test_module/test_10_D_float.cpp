#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, Eigen::Dynamic> test_float_10_D(const Eigen::Matrix<float, 10, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_10_D()
{
	boost::python::def("test_float_10_D",test_float_10_D);
}

