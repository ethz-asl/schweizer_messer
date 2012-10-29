#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, 4> test_float_01_04(const Eigen::Matrix<float, 1, 4> & M)
{
	return M;
}
void export_float_01_04()
{
	boost::python::def("test_float_01_04",test_float_01_04);
}

