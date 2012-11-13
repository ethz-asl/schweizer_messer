#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, 16> test_int_14_16(const Eigen::Matrix<int, 14, 16> & M)
{
	return M;
}
void export_int_14_16()
{
	boost::python::def("test_int_14_16",test_int_14_16);
}

