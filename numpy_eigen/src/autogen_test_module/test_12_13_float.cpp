#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 13> test_float_12_13(const Eigen::Matrix<float, 12, 13> & M)
{
	return M;
}
void export_float_12_13()
{
	boost::python::def("test_float_12_13",test_float_12_13);
}

