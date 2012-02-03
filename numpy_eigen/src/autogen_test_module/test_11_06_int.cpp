#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, 6> test_int_11_06(const Eigen::Matrix<int, 11, 6> & M)
{
	return M;
}
void export_int_11_06()
{
	boost::python::def("test_int_11_06",test_int_11_06);
}

