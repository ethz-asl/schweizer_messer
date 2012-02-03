#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, 6> test_int_14_06(const Eigen::Matrix<int, 14, 6> & M)
{
	return M;
}
void export_int_14_06()
{
	boost::python::def("test_int_14_06",test_int_14_06);
}

