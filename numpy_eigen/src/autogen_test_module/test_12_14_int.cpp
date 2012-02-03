#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 14> test_int_12_14(const Eigen::Matrix<int, 12, 14> & M)
{
	return M;
}
void export_int_12_14()
{
	boost::python::def("test_int_12_14",test_int_12_14);
}

