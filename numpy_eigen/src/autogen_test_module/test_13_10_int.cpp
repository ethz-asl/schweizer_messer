#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 10> test_int_13_10(const Eigen::Matrix<int, 13, 10> & M)
{
	return M;
}
void export_int_13_10()
{
	boost::python::def("test_int_13_10",test_int_13_10);
}

