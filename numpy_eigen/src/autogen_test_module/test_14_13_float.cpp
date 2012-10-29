#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 13> test_float_14_13(const Eigen::Matrix<float, 14, 13> & M)
{
	return M;
}
void export_float_14_13()
{
	boost::python::def("test_float_14_13",test_float_14_13);
}

