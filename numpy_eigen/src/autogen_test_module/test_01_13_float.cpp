#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 1, 13> test_float_01_13(const Eigen::Matrix<float, 1, 13> & M)
{
	return M;
}
void export_float_01_13()
{
	boost::python::def("test_float_01_13",test_float_01_13);
}

