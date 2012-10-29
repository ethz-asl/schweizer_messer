#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 4> test_double_11_04(const Eigen::Matrix<double, 11, 4> & M)
{
	return M;
}
void export_double_11_04()
{
	boost::python::def("test_double_11_04",test_double_11_04);
}

