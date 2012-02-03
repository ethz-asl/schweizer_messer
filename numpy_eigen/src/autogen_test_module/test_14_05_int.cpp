#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, 5> test_int_14_05(const Eigen::Matrix<int, 14, 5> & M)
{
	return M;
}
void export_int_14_05()
{
	boost::python::def("test_int_14_05",test_int_14_05);
}

