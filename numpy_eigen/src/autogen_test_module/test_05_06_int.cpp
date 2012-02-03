#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 5, 6> test_int_05_06(const Eigen::Matrix<int, 5, 6> & M)
{
	return M;
}
void export_int_05_06()
{
	boost::python::def("test_int_05_06",test_int_05_06);
}

