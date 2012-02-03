#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 15> test_int_13_15(const Eigen::Matrix<int, 13, 15> & M)
{
	return M;
}
void export_int_13_15()
{
	boost::python::def("test_int_13_15",test_int_13_15);
}

