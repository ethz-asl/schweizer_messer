#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 12> test_double_05_12(const Eigen::Matrix<double, 5, 12> & M)
{
	return M;
}
void export_double_05_12()
{
	boost::python::def("test_double_05_12",test_double_05_12);
}

