#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 5, 16> test_int_05_16(const Eigen::Matrix<int, 5, 16> & M)
{
	return M;
}
void export_int_05_16()
{
	boost::python::def("test_int_05_16",test_int_05_16);
}

