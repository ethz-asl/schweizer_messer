#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 12> test_float_02_12(const Eigen::Matrix<float, 2, 12> & M)
{
	return M;
}
void export_float_02_12()
{
	boost::python::def("test_float_02_12",test_float_02_12);
}

