#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 1, 2> test_int_01_02(const Eigen::Matrix<int, 1, 2> & M)
{
	return M;
}
void export_int_01_02()
{
	boost::python::def("test_int_01_02",test_int_01_02);
}

