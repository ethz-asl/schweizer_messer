#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 11> test_int_02_11(const Eigen::Matrix<int, 2, 11> & M)
{
	return M;
}
void export_int_02_11()
{
	boost::python::def("test_int_02_11",test_int_02_11);
}

