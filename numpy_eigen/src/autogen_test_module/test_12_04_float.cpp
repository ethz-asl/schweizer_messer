#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 4> test_float_12_04(const Eigen::Matrix<float, 12, 4> & M)
{
	return M;
}
void export_float_12_04()
{
	boost::python::def("test_float_12_04",test_float_12_04);
}

