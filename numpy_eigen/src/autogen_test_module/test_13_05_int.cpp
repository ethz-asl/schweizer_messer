#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 5> test_int_13_05(const Eigen::Matrix<int, 13, 5> & M)
{
	return M;
}
void export_int_13_05()
{
	boost::python::def("test_int_13_05",test_int_13_05);
}

