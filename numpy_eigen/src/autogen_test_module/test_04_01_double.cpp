#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 1> test_double_04_01(const Eigen::Matrix<double, 4, 1> & M)
{
	return M;
}
void export_double_04_01()
{
	boost::python::def("test_double_04_01",test_double_04_01);
}

