#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 2, 4> test_double_02_04(const Eigen::Matrix<double, 2, 4> & M)
{
	return M;
}
void export_double_02_04()
{
	boost::python::def("test_double_02_04",test_double_02_04);
}

