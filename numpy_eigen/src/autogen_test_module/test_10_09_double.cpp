#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 10, 9> test_double_10_09(const Eigen::Matrix<double, 10, 9> & M)
{
	return M;
}
void export_double_10_09()
{
	boost::python::def("test_double_10_09",test_double_10_09);
}

