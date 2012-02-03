#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 8> test_int_D_08(const Eigen::Matrix<int, Eigen::Dynamic, 8> & M)
{
	return M;
}
void export_int_D_08()
{
	boost::python::def("test_int_D_08",test_int_D_08);
}

