#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 15> test_float_15_15(const Eigen::Matrix<float, 15, 15> & M)
{
	return M;
}
void export_float_15_15()
{
	boost::python::def("test_float_15_15",test_float_15_15);
}

