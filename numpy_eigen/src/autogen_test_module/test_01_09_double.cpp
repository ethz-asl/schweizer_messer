#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 1, 9> test_double_01_09(const Eigen::Matrix<double, 1, 9> & M)
{
	return M;
}
void export_double_01_09()
{
	boost::python::def("test_double_01_09",test_double_01_09);
}

