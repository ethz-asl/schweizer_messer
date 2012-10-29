#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 3> test_int_13_03(const Eigen::Matrix<int, 13, 3> & M)
{
	return M;
}
void export_int_13_03()
{
	boost::python::def("test_int_13_03",test_int_13_03);
}

