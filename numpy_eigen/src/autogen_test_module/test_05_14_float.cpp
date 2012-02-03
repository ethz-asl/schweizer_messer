#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 14> test_float_05_14(const Eigen::Matrix<float, 5, 14> & M)
{
	return M;
}
void export_float_05_14()
{
	boost::python::def("test_float_05_14",test_float_05_14);
}

