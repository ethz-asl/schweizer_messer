#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 15> test_int_09_15(const Eigen::Matrix<int, 9, 15> & M)
{
	return M;
}
void export_int_09_15()
{
	boost::python::def("test_int_09_15",test_int_09_15);
}

