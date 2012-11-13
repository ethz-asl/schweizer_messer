#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 11> test_int_09_11(const Eigen::Matrix<int, 9, 11> & M)
{
	return M;
}
void export_int_09_11()
{
	boost::python::def("test_int_09_11",test_int_09_11);
}

