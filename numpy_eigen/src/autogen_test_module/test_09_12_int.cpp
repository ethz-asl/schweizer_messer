#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 12> test_int_09_12(const Eigen::Matrix<int, 9, 12> & M)
{
	return M;
}
void export_int_09_12()
{
	boost::python::def("test_int_09_12",test_int_09_12);
}

