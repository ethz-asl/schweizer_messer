#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 8> test_float_16_08(const Eigen::Matrix<float, 16, 8> & M)
{
	return M;
}
void export_float_16_08()
{
	boost::python::def("test_float_16_08",test_float_16_08);
}

