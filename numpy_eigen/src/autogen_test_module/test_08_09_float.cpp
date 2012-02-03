#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 9> test_float_08_09(const Eigen::Matrix<float, 8, 9> & M)
{
	return M;
}
void export_float_08_09()
{
	boost::python::def("test_float_08_09",test_float_08_09);
}

