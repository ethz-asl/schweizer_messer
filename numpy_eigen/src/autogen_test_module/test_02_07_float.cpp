#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 7> test_float_02_07(const Eigen::Matrix<float, 2, 7> & M)
{
	return M;
}
void export_float_02_07()
{
	boost::python::def("test_float_02_07",test_float_02_07);
}

