#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 15> test_int_D_15(const Eigen::Matrix<int, Eigen::Dynamic, 15> & M)
{
	return M;
}
void export_int_D_15()
{
	boost::python::def("test_int_D_15",test_int_D_15);
}

