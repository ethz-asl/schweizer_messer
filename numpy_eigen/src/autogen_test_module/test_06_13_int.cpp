#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 13> test_int_06_13(const Eigen::Matrix<int, 6, 13> & M)
{
	return M;
}
void export_int_06_13()
{
	boost::python::def("test_int_06_13",test_int_06_13);
}

