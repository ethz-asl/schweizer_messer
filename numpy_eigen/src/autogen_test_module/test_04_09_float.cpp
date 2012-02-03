#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 9> test_float_04_09(const Eigen::Matrix<float, 4, 9> & M)
{
	return M;
}
void export_float_04_09()
{
	boost::python::def("test_float_04_09",test_float_04_09);
}

