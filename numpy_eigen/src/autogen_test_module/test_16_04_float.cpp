#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 4> test_float_16_04(const Eigen::Matrix<float, 16, 4> & M)
{
	return M;
}
void export_float_16_04()
{
	boost::python::def("test_float_16_04",test_float_16_04);
}

