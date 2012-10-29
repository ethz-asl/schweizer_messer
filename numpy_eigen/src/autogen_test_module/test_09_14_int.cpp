#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 14> test_int_09_14(const Eigen::Matrix<int, 9, 14> & M)
{
	return M;
}
void export_int_09_14()
{
	boost::python::def("test_int_09_14",test_int_09_14);
}

