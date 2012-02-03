#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 15> test_float_06_15(const Eigen::Matrix<float, 6, 15> & M)
{
	return M;
}
void export_float_06_15()
{
	boost::python::def("test_float_06_15",test_float_06_15);
}

