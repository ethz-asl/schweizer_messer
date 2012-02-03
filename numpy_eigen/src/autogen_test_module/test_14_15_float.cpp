#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 15> test_float_14_15(const Eigen::Matrix<float, 14, 15> & M)
{
	return M;
}
void export_float_14_15()
{
	boost::python::def("test_float_14_15",test_float_14_15);
}

