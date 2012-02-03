#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, 16> test_int_04_16(const Eigen::Matrix<int, 4, 16> & M)
{
	return M;
}
void export_int_04_16()
{
	boost::python::def("test_int_04_16",test_int_04_16);
}

