#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 3, 7> test_double_03_07(const Eigen::Matrix<double, 3, 7> & M)
{
	return M;
}
void export_double_03_07()
{
	boost::python::def("test_double_03_07",test_double_03_07);
}

