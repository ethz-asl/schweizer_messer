#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 3> test_int_15_03(const Eigen::Matrix<int, 15, 3> & M)
{
	return M;
}
void export_int_15_03()
{
	boost::python::def("test_int_15_03",test_int_15_03);
}

