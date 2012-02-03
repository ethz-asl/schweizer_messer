#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 2> test_int_D_02(const Eigen::Matrix<int, Eigen::Dynamic, 2> & M)
{
	return M;
}
void export_int_D_02()
{
	boost::python::def("test_int_D_02",test_int_D_02);
}

