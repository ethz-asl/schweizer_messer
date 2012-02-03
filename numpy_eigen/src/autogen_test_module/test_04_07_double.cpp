#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 7> test_double_04_07(const Eigen::Matrix<double, 4, 7> & M)
{
	return M;
}
void export_double_04_07()
{
	boost::python::def("test_double_04_07",test_double_04_07);
}

