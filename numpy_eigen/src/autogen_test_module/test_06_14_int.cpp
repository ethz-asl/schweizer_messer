#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 14> test_int_06_14(const Eigen::Matrix<int, 6, 14> & M)
{
	return M;
}
void export_int_06_14()
{
	boost::python::def("test_int_06_14",test_int_06_14);
}

