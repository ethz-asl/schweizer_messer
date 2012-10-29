#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 1> test_float_03_01(const Eigen::Matrix<float, 3, 1> & M)
{
	return M;
}
void export_float_03_01()
{
	boost::python::def("test_float_03_01",test_float_03_01);
}

