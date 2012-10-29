#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 6> test_float_04_06(const Eigen::Matrix<float, 4, 6> & M)
{
	return M;
}
void export_float_04_06()
{
	boost::python::def("test_float_04_06",test_float_04_06);
}

