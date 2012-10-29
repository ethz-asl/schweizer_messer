#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 14> test_int_03_14(const Eigen::Matrix<int, 3, 14> & M)
{
	return M;
}
void export_int_03_14()
{
	boost::python::def("test_int_03_14",test_int_03_14);
}

