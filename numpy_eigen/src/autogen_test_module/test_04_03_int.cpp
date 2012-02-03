#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, 3> test_int_04_03(const Eigen::Matrix<int, 4, 3> & M)
{
	return M;
}
void export_int_04_03()
{
	boost::python::def("test_int_04_03",test_int_04_03);
}

