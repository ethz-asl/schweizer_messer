#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, Eigen::Dynamic> test_float_05_D(const Eigen::Matrix<float, 5, Eigen::Dynamic> & M)
{
	return M;
}
void export_float_05_D()
{
	boost::python::def("test_float_05_D",test_float_05_D);
}

