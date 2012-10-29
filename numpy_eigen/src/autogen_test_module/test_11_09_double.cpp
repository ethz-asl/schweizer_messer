#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 9> test_double_11_09(const Eigen::Matrix<double, 11, 9> & M)
{
	return M;
}
void export_double_11_09()
{
	boost::python::def("test_double_11_09",test_double_11_09);
}

