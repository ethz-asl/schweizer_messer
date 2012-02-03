#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 15> test_float_16_15(const Eigen::Matrix<float, 16, 15> & M)
{
	return M;
}
void export_float_16_15()
{
	boost::python::def("test_float_16_15",test_float_16_15);
}

