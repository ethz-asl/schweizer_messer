#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, Eigen::Dynamic> test_float_15_D(const Eigen::Matrix<float, 15, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_15_D()
{
	boost::python::def("test_float_15_D",test_float_15_D);
}

