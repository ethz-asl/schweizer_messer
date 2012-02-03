#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 6> test_float_10_06(const Eigen::Matrix<float, 10, 6> & M)
{
	return M;
}
void export_float_10_06()
{
	boost::python::def("test_float_10_06",test_float_10_06);
}

