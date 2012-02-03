#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, 6> test_float_07_06(const Eigen::Matrix<float, 7, 6> & M)
{
	return M;
}
void export_float_07_06()
{
	boost::python::def("test_float_07_06",test_float_07_06);
}

