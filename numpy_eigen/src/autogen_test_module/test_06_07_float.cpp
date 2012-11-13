#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 7> test_float_06_07(const Eigen::Matrix<float, 6, 7> & M)
{
	return M;
}
void export_float_06_07()
{
	boost::python::def("test_float_06_07",test_float_06_07);
}

