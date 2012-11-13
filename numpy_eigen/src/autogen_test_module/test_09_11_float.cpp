#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 11> test_float_09_11(const Eigen::Matrix<float, 9, 11> & M)
{
	return M;
}
void export_float_09_11()
{
	boost::python::def("test_float_09_11",test_float_09_11);
}

