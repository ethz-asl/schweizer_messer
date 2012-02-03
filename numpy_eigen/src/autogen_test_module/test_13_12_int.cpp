#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 12> test_int_13_12(const Eigen::Matrix<int, 13, 12> & M)
{
	return M;
}
void export_int_13_12()
{
	boost::python::def("test_int_13_12",test_int_13_12);
}

