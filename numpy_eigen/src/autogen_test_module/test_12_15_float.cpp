#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 15> test_float_12_15(const Eigen::Matrix<float, 12, 15> & M)
{
	return M;
}
void export_float_12_15()
{
	boost::python::def("test_float_12_15",test_float_12_15);
}

