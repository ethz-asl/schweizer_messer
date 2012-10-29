#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 6> test_int_06_06(const Eigen::Matrix<int, 6, 6> & M)
{
	return M;
}
void export_int_06_06()
{
	boost::python::def("test_int_06_06",test_int_06_06);
}

