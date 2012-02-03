#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 6> test_int_D_06(const Eigen::Matrix<int, Eigen::Dynamic, 6> & M)
{
	return M;
}
void export_int_D_06()
{
	boost::python::def("test_int_D_06",test_int_D_06);
}

