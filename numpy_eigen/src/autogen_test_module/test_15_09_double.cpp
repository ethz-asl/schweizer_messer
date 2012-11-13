#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 15, 9> test_double_15_09(const Eigen::Matrix<double, 15, 9> & M)
{
	return M;
}
void export_double_15_09()
{
	boost::python::def("test_double_15_09",test_double_15_09);
}

