#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 11> test_float_14_11(const Eigen::Matrix<float, 14, 11> & M)
{
	return M;
}
void export_float_14_11()
{
	boost::python::def("test_float_14_11",test_float_14_11);
}

