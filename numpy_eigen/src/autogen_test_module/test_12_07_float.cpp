#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 7> test_float_12_07(const Eigen::Matrix<float, 12, 7> & M)
{
	return M;
}
void export_float_12_07()
{
	boost::python::def("test_float_12_07",test_float_12_07);
}

