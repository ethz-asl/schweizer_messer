#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 6> test_float_12_06(const Eigen::Matrix<float, 12, 6> & M)
{
	return M;
}
void export_float_12_06()
{
	boost::python::def("test_float_12_06",test_float_12_06);
}

