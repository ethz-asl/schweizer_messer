#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 1> test_float_13_01(const Eigen::Matrix<float, 13, 1> & M)
{
	return M;
}
void export_float_13_01()
{
	boost::python::def("test_float_13_01",test_float_13_01);
}

