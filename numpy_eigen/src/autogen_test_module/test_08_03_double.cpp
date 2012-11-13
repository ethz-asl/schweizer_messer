#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 8, 3> test_double_08_03(const Eigen::Matrix<double, 8, 3> & M)
{
	return M;
}
void export_double_08_03()
{
	boost::python::def("test_double_08_03",test_double_08_03);
}

