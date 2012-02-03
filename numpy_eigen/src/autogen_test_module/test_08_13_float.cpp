#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 13> test_float_08_13(const Eigen::Matrix<float, 8, 13> & M)
{
	return M;
}
void export_float_08_13()
{
	boost::python::def("test_float_08_13",test_float_08_13);
}

