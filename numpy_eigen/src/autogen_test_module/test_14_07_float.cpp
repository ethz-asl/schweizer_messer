#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 7> test_float_14_07(const Eigen::Matrix<float, 14, 7> & M)
{
	return M;
}
void export_float_14_07()
{
	boost::python::def("test_float_14_07",test_float_14_07);
}

