#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 1> test_float_09_01(const Eigen::Matrix<float, 9, 1> & M)
{
	return M;
}
void export_float_09_01()
{
	boost::python::def("test_float_09_01",test_float_09_01);
}

