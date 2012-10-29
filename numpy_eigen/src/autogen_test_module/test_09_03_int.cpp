#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 3> test_int_09_03(const Eigen::Matrix<int, 9, 3> & M)
{
	return M;
}
void export_int_09_03()
{
	boost::python::def("test_int_09_03",test_int_09_03);
}

