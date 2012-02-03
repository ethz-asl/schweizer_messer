#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 1> test_float_06_01(const Eigen::Matrix<float, 6, 1> & M)
{
	return M;
}
void export_float_06_01()
{
	boost::python::def("test_float_06_01",test_float_06_01);
}

