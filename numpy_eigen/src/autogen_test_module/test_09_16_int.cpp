#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 16> test_int_09_16(const Eigen::Matrix<int, 9, 16> & M)
{
	return M;
}
void export_int_09_16()
{
	boost::python::def("test_int_09_16",test_int_09_16);
}

