#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 9> test_float_12_09(const Eigen::Matrix<float, 12, 9> & M)
{
	return M;
}
void export_float_12_09()
{
	boost::python::def("test_float_12_09",test_float_12_09);
}

