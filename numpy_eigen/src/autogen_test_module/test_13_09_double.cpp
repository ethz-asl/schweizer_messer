#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 9> test_double_13_09(const Eigen::Matrix<double, 13, 9> & M)
{
	return M;
}
void export_double_13_09()
{
	boost::python::def("test_double_13_09",test_double_13_09);
}

