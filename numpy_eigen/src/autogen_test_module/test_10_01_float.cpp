#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 1> test_float_10_01(const Eigen::Matrix<float, 10, 1> & M)
{
	return M;
}
void export_float_10_01()
{
	boost::python::def("test_float_10_01",test_float_10_01);
}

