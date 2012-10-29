#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 10, 5> test_int_10_05(const Eigen::Matrix<int, 10, 5> & M)
{
	return M;
}
void export_int_10_05()
{
	boost::python::def("test_int_10_05",test_int_10_05);
}

