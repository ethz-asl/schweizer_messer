#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 9, 7> test_int_09_07(const Eigen::Matrix<int, 9, 7> & M)
{
	return M;
}
void export_int_09_07()
{
	boost::python::def("test_int_09_07",test_int_09_07);
}

