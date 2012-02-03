#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 3> test_int_12_03(const Eigen::Matrix<int, 12, 3> & M)
{
	return M;
}
void export_int_12_03()
{
	boost::python::def("test_int_12_03",test_int_12_03);
}

