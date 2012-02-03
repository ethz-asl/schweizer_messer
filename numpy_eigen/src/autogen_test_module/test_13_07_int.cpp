#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 7> test_int_13_07(const Eigen::Matrix<int, 13, 7> & M)
{
	return M;
}
void export_int_13_07()
{
	boost::python::def("test_int_13_07",test_int_13_07);
}

