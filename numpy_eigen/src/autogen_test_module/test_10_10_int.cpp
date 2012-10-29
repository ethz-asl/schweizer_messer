#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 10, 10> test_int_10_10(const Eigen::Matrix<int, 10, 10> & M)
{
	return M;
}
void export_int_10_10()
{
	boost::python::def("test_int_10_10",test_int_10_10);
}

