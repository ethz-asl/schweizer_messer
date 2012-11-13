#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 2> test_float_05_02(const Eigen::Matrix<float, 5, 2> & M)
{
	return M;
}
void export_float_05_02()
{
	boost::python::def("test_float_05_02",test_float_05_02);
}

