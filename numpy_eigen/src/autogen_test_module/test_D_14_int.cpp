#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 14> test_int_D_14(const Eigen::Matrix<int, Eigen::Dynamic, 14> & M)
{
	return M;
}
void export_int_D_14()
{
	boost::python::def("test_int_D_14",test_int_D_14);
}

