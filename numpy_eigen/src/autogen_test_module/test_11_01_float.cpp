#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 11, 1> test_float_11_01(const Eigen::Matrix<float, 11, 1> & M)
{
	return M;
}
void export_float_11_01()
{
	boost::python::def("test_float_11_01",test_float_11_01);
}

