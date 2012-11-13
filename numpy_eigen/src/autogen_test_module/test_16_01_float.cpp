#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 1> test_float_16_01(const Eigen::Matrix<float, 16, 1> & M)
{
	return M;
}
void export_float_16_01()
{
	boost::python::def("test_float_16_01",test_float_16_01);
}

