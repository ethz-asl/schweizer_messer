#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 11, 11> test_float_11_11(const Eigen::Matrix<float, 11, 11> & M)
{
	return M;
}
void export_float_11_11()
{
	boost::python::def("test_float_11_11",test_float_11_11);
}

