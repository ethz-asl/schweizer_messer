#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 3> test_int_D_03(const Eigen::Matrix<int, Eigen::Dynamic, 3> & M)
{
	return M;
}
void export_int_D_03()
{
	boost::python::def("test_int_D_03",test_int_D_03);
}

