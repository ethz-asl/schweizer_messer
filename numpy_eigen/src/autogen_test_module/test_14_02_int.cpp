#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, 2> test_int_14_02(const Eigen::Matrix<int, 14, 2> & M)
{
	return M;
}
void export_int_14_02()
{
	boost::python::def("test_int_14_02",test_int_14_02);
}

