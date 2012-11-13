#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 9> test_float_16_09(const Eigen::Matrix<float, 16, 9> & M)
{
	return M;
}
void export_float_16_09()
{
	boost::python::def("test_float_16_09",test_float_16_09);
}

