#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, 16> test_int_08_16(const Eigen::Matrix<int, 8, 16> & M)
{
	return M;
}
void export_int_08_16()
{
	boost::python::def("test_int_08_16",test_int_08_16);
}

