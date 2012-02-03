#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 2> test_float_10_02(const Eigen::Matrix<float, 10, 2> & M)
{
	return M;
}
void export_float_10_02()
{
	boost::python::def("test_float_10_02",test_float_10_02);
}

