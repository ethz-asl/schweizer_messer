#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 16> test_float_04_16(const Eigen::Matrix<float, 4, 16> & M)
{
	return M;
}
void export_float_04_16()
{
	boost::python::def("test_float_04_16",test_float_04_16);
}

