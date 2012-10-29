#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 1> test_double_05_01(const Eigen::Matrix<double, 5, 1> & M)
{
	return M;
}
void export_double_05_01()
{
	boost::python::def("test_double_05_01",test_double_05_01);
}

