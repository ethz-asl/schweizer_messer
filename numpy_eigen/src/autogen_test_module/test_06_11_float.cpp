#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 11> test_float_06_11(const Eigen::Matrix<float, 6, 11> & M)
{
	return M;
}
void export_float_06_11()
{
	boost::python::def("test_float_06_11",test_float_06_11);
}

