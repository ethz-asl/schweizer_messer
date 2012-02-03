#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 5> test_int_12_05(const Eigen::Matrix<int, 12, 5> & M)
{
	return M;
}
void export_int_12_05()
{
	boost::python::def("test_int_12_05",test_int_12_05);
}

