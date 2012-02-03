#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 14, 1> test_double_14_01(const Eigen::Matrix<double, 14, 1> & M)
{
	return M;
}
void export_double_14_01()
{
	boost::python::def("test_double_14_01",test_double_14_01);
}

