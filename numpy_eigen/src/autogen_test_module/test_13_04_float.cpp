#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 4> test_float_13_04(const Eigen::Matrix<float, 13, 4> & M)
{
	return M;
}
void export_float_13_04()
{
	boost::python::def("test_float_13_04",test_float_13_04);
}

