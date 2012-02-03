#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 5> test_float_16_05(const Eigen::Matrix<float, 16, 5> & M)
{
	return M;
}
void export_float_16_05()
{
	boost::python::def("test_float_16_05",test_float_16_05);
}

