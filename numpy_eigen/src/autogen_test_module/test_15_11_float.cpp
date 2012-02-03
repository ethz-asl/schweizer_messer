#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 11> test_float_15_11(const Eigen::Matrix<float, 15, 11> & M)
{
	return M;
}
void export_float_15_11()
{
	boost::python::def("test_float_15_11",test_float_15_11);
}

