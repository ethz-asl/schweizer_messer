#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 11> test_float_12_11(const Eigen::Matrix<float, 12, 11> & M)
{
	return M;
}
void export_float_12_11()
{
	boost::python::def("test_float_12_11",test_float_12_11);
}

