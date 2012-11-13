#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 12, 4> test_double_12_04(const Eigen::Matrix<double, 12, 4> & M)
{
	return M;
}
void export_double_12_04()
{
	boost::python::def("test_double_12_04",test_double_12_04);
}

