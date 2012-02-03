#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 12> test_float_03_12(const Eigen::Matrix<float, 3, 12> & M)
{
	return M;
}
void export_float_03_12()
{
	boost::python::def("test_float_03_12",test_float_03_12);
}

