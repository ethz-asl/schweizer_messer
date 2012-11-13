#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 9> test_float_D_09(const Eigen::Matrix<float, Eigen::Dynamic, 9> & M)
{
	return M;
}
void export_float_D_09()
{
	boost::python::def("test_float_D_09",test_float_D_09);
}

