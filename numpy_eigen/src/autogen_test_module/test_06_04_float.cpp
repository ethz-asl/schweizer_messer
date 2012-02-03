#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 4> test_float_06_04(const Eigen::Matrix<float, 6, 4> & M)
{
	return M;
}
void export_float_06_04()
{
	boost::python::def("test_float_06_04",test_float_06_04);
}

