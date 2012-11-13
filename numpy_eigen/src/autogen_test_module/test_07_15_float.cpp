#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, 15> test_float_07_15(const Eigen::Matrix<float, 7, 15> & M)
{
	return M;
}
void export_float_07_15()
{
	boost::python::def("test_float_07_15",test_float_07_15);
}

