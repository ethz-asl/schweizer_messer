#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 5> test_double_04_05(const Eigen::Matrix<double, 4, 5> & M)
{
	return M;
}
void export_double_04_05()
{
	boost::python::def("test_double_04_05",test_double_04_05);
}

