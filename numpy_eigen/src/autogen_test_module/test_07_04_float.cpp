#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, 4> test_float_07_04(const Eigen::Matrix<float, 7, 4> & M)
{
	return M;
}
void export_float_07_04()
{
	boost::python::def("test_float_07_04",test_float_07_04);
}

