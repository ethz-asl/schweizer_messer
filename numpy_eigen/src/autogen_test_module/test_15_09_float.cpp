#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 9> test_float_15_09(const Eigen::Matrix<float, 15, 9> & M)
{
	return M;
}
void export_float_15_09()
{
	boost::python::def("test_float_15_09",test_float_15_09);
}

