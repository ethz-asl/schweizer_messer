#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 11> test_int_D_11(const Eigen::Matrix<int, Eigen::Dynamic, 11> & M)
{
	return M;
}
void export_int_D_11()
{
	boost::python::def("test_int_D_11",test_int_D_11);
}

