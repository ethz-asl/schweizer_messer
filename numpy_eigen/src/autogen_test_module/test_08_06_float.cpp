#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 6> test_float_08_06(const Eigen::Matrix<float, 8, 6> & M)
{
	return M;
}
void export_float_08_06()
{
	boost::python::def("test_float_08_06",test_float_08_06);
}

