#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 6> test_float_05_06(const Eigen::Matrix<float, 5, 6> & M)
{
	return M;
}
void export_float_05_06()
{
	boost::python::def("test_float_05_06",test_float_05_06);
}

