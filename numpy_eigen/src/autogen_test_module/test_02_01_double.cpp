#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 1> test_double_02_01(const Eigen::Matrix<double, 2, 1> & M)
{
	return M;
}
void export_double_02_01()
{
	boost::python::def("test_double_02_01",test_double_02_01);
}

