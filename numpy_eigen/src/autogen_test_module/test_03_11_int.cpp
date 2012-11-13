#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 11> test_int_03_11(const Eigen::Matrix<int, 3, 11> & M)
{
	return M;
}
void export_int_03_11()
{
	boost::python::def("test_int_03_11",test_int_03_11);
}

