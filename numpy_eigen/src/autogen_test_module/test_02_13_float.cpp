#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 13> test_float_02_13(const Eigen::Matrix<float, 2, 13> & M)
{
	return M;
}
void export_float_02_13()
{
	boost::python::def("test_float_02_13",test_float_02_13);
}

