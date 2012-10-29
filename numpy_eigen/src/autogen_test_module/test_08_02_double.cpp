#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 8, 2> test_double_08_02(const Eigen::Matrix<double, 8, 2> & M)
{
	return M;
}
void export_double_08_02()
{
	boost::python::def("test_double_08_02",test_double_08_02);
}

