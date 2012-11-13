#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 5> test_float_06_05(const Eigen::Matrix<float, 6, 5> & M)
{
	return M;
}
void export_float_06_05()
{
	boost::python::def("test_float_06_05",test_float_06_05);
}

