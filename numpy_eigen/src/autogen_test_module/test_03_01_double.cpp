#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 3, 1> test_double_03_01(const Eigen::Matrix<double, 3, 1> & M)
{
	return M;
}
void export_double_03_01()
{
	boost::python::def("test_double_03_01",test_double_03_01);
}

