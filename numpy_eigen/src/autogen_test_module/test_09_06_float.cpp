#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 6> test_float_09_06(const Eigen::Matrix<float, 9, 6> & M)
{
	return M;
}
void export_float_09_06()
{
	boost::python::def("test_float_09_06",test_float_09_06);
}

