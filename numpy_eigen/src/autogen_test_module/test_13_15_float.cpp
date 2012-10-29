#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 15> test_float_13_15(const Eigen::Matrix<float, 13, 15> & M)
{
	return M;
}
void export_float_13_15()
{
	boost::python::def("test_float_13_15",test_float_13_15);
}

