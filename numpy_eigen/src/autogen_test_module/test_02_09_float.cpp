#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 9> test_float_02_09(const Eigen::Matrix<float, 2, 9> & M)
{
	return M;
}
void export_float_02_09()
{
	boost::python::def("test_float_02_09",test_float_02_09);
}

