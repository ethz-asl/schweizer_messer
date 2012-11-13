#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 12, 9> test_double_12_09(const Eigen::Matrix<double, 12, 9> & M)
{
	return M;
}
void export_double_12_09()
{
	boost::python::def("test_double_12_09",test_double_12_09);
}

