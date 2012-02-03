#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 4> test_float_14_04(const Eigen::Matrix<float, 14, 4> & M)
{
	return M;
}
void export_float_14_04()
{
	boost::python::def("test_float_14_04",test_float_14_04);
}

