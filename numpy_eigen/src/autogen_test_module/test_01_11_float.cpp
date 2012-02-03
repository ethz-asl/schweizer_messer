#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, 11> test_float_01_11(const Eigen::Matrix<float, 1, 11> & M)
{
	return M;
}
void export_float_01_11()
{
	boost::python::def("test_float_01_11",test_float_01_11);
}

