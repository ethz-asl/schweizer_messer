#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 6, 9> test_double_06_09(const Eigen::Matrix<double, 6, 9> & M)
{
	return M;
}
void export_double_06_09()
{
	boost::python::def("test_double_06_09",test_double_06_09);
}

