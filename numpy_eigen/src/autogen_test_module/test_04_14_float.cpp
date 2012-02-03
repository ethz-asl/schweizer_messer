#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 14> test_float_04_14(const Eigen::Matrix<float, 4, 14> & M)
{
	return M;
}
void export_float_04_14()
{
	boost::python::def("test_float_04_14",test_float_04_14);
}

