#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 16, 3> test_double_16_03(const Eigen::Matrix<double, 16, 3> & M)
{
	return M;
}
void export_double_16_03()
{
	boost::python::def("test_double_16_03",test_double_16_03);
}

