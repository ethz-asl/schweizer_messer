#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 13> test_float_03_13(const Eigen::Matrix<float, 3, 13> & M)
{
	return M;
}
void export_float_03_13()
{
	boost::python::def("test_float_03_13",test_float_03_13);
}

