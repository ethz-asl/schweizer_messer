#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 4> test_int_13_04(const Eigen::Matrix<int, 13, 4> & M)
{
	return M;
}
void export_int_13_04()
{
	boost::python::def("test_int_13_04",test_int_13_04);
}

