#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 13> test_float_15_13(const Eigen::Matrix<float, 15, 13> & M)
{
	return M;
}
void export_float_15_13()
{
	boost::python::def("test_float_15_13",test_float_15_13);
}

