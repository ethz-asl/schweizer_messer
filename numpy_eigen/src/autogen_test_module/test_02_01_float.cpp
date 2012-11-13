#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 1> test_float_02_01(const Eigen::Matrix<float, 2, 1> & M)
{
	return M;
}
void export_float_02_01()
{
	boost::python::def("test_float_02_01",test_float_02_01);
}

