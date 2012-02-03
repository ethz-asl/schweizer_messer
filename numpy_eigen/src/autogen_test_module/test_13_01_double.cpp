#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 1> test_double_13_01(const Eigen::Matrix<double, 13, 1> & M)
{
	return M;
}
void export_double_13_01()
{
	boost::python::def("test_double_13_01",test_double_13_01);
}

