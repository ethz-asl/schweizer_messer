#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 13> test_int_D_13(const Eigen::Matrix<int, Eigen::Dynamic, 13> & M)
{
	return M;
}
void export_int_D_13()
{
	boost::python::def("test_int_D_13",test_int_D_13);
}

