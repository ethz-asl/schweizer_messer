#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 2> test_int_02_02(const Eigen::Matrix<int, 2, 2> & M)
{
	return M;
}
void export_int_02_02()
{
	boost::python::def("test_int_02_02",test_int_02_02);
}

