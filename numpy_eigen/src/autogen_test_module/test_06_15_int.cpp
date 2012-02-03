#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 15> test_int_06_15(const Eigen::Matrix<int, 6, 15> & M)
{
	return M;
}
void export_int_06_15()
{
	boost::python::def("test_int_06_15",test_int_06_15);
}

