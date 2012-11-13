#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, 13> test_int_11_13(const Eigen::Matrix<int, 11, 13> & M)
{
	return M;
}
void export_int_11_13()
{
	boost::python::def("test_int_11_13",test_int_11_13);
}

