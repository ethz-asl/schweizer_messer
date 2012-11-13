#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 16> test_int_D_16(const Eigen::Matrix<int, Eigen::Dynamic, 16> & M)
{
	return M;
}
void export_int_D_16()
{
	boost::python::def("test_int_D_16",test_int_D_16);
}

