#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 11> test_int_15_11(const Eigen::Matrix<int, 15, 11> & M)
{
	return M;
}
void export_int_15_11()
{
	boost::python::def("test_int_15_11",test_int_15_11);
}

