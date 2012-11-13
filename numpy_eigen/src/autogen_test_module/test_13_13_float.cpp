#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 13> test_float_13_13(const Eigen::Matrix<float, 13, 13> & M)
{
	return M;
}
void export_float_13_13()
{
	boost::python::def("test_float_13_13",test_float_13_13);
}

