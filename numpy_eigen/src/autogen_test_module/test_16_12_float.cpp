#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 12> test_float_16_12(const Eigen::Matrix<float, 16, 12> & M)
{
	return M;
}
void export_float_16_12()
{
	boost::python::def("test_float_16_12",test_float_16_12);
}

