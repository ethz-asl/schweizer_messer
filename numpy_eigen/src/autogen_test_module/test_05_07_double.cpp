#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 7> test_double_05_07(const Eigen::Matrix<double, 5, 7> & M)
{
	return M;
}
void export_double_05_07()
{
	boost::python::def("test_double_05_07",test_double_05_07);
}

