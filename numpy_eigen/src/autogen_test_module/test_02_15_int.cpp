#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 15> test_int_02_15(const Eigen::Matrix<int, 2, 15> & M)
{
	return M;
}
void export_int_02_15()
{
	boost::python::def("test_int_02_15",test_int_02_15);
}

