#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 16, 11> test_int_16_11(const Eigen::Matrix<int, 16, 11> & M)
{
	return M;
}
void export_int_16_11()
{
	boost::python::def("test_int_16_11",test_int_16_11);
}

