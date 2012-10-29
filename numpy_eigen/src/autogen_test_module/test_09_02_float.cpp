#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 2> test_float_09_02(const Eigen::Matrix<float, 9, 2> & M)
{
	return M;
}
void export_float_09_02()
{
	boost::python::def("test_float_09_02",test_float_09_02);
}

