#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 11> test_float_16_11(const Eigen::Matrix<float, 16, 11> & M)
{
	return M;
}
void export_float_16_11()
{
	boost::python::def("test_float_16_11",test_float_16_11);
}

