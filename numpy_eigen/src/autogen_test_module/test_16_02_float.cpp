#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 2> test_float_16_02(const Eigen::Matrix<float, 16, 2> & M)
{
	return M;
}
void export_float_16_02()
{
	boost::python::def("test_float_16_02",test_float_16_02);
}

