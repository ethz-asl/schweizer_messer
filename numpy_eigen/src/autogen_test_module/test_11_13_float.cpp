#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 11, 13> test_float_11_13(const Eigen::Matrix<float, 11, 13> & M)
{
	return M;
}
void export_float_11_13()
{
	boost::python::def("test_float_11_13",test_float_11_13);
}

