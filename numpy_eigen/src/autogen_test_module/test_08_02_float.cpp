#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 2> test_float_08_02(const Eigen::Matrix<float, 8, 2> & M)
{
	return M;
}
void export_float_08_02()
{
	boost::python::def("test_float_08_02",test_float_08_02);
}

