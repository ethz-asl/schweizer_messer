#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 12> test_float_15_12(const Eigen::Matrix<float, 15, 12> & M)
{
	return M;
}
void export_float_15_12()
{
	boost::python::def("test_float_15_12",test_float_15_12);
}

