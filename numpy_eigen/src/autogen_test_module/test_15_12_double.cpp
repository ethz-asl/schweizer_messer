#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 15, 12> test_double_15_12(const Eigen::Matrix<double, 15, 12> & M)
{
	return M;
}
void export_double_15_12()
{
	boost::python::def("test_double_15_12",test_double_15_12);
}

