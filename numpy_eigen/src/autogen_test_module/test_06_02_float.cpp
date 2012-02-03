#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 2> test_float_06_02(const Eigen::Matrix<float, 6, 2> & M)
{
	return M;
}
void export_float_06_02()
{
	boost::python::def("test_float_06_02",test_float_06_02);
}

