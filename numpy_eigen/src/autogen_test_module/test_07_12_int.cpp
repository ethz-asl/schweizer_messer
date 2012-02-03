#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 7, 12> test_int_07_12(const Eigen::Matrix<int, 7, 12> & M)
{
	return M;
}
void export_int_07_12()
{
	boost::python::def("test_int_07_12",test_int_07_12);
}

