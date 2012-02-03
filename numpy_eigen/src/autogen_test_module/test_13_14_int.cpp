#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 14> test_int_13_14(const Eigen::Matrix<int, 13, 14> & M)
{
	return M;
}
void export_int_13_14()
{
	boost::python::def("test_int_13_14",test_int_13_14);
}

