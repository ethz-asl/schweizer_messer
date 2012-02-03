#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 7> test_double_02_07(const Eigen::Matrix<double, 2, 7> & M)
{
	return M;
}
void export_double_02_07()
{
	boost::python::def("test_double_02_07",test_double_02_07);
}

