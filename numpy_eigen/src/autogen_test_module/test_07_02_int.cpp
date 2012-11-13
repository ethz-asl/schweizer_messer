#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 7, 2> test_int_07_02(const Eigen::Matrix<int, 7, 2> & M)
{
	return M;
}
void export_int_07_02()
{
	boost::python::def("test_int_07_02",test_int_07_02);
}

