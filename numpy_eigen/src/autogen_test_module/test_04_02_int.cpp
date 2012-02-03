#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, 2> test_int_04_02(const Eigen::Matrix<int, 4, 2> & M)
{
	return M;
}
void export_int_04_02()
{
	boost::python::def("test_int_04_02",test_int_04_02);
}

