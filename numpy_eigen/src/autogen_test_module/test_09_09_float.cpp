#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 9> test_float_09_09(const Eigen::Matrix<float, 9, 9> & M)
{
	return M;
}
void export_float_09_09()
{
	boost::python::def("test_float_09_09",test_float_09_09);
}

