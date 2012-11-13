#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 16> test_int_06_16(const Eigen::Matrix<int, 6, 16> & M)
{
	return M;
}
void export_int_06_16()
{
	boost::python::def("test_int_06_16",test_int_06_16);
}

