#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 5, 13> test_double_05_13(const Eigen::Matrix<double, 5, 13> & M)
{
	return M;
}
void export_double_05_13()
{
	boost::python::def("test_double_05_13",test_double_05_13);
}

