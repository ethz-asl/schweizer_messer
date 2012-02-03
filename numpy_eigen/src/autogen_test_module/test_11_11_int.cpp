#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, 11> test_int_11_11(const Eigen::Matrix<int, 11, 11> & M)
{
	return M;
}
void export_int_11_11()
{
	boost::python::def("test_int_11_11",test_int_11_11);
}

