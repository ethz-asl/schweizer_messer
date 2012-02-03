#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 13> test_float_05_13(const Eigen::Matrix<float, 5, 13> & M)
{
	return M;
}
void export_float_05_13()
{
	boost::python::def("test_float_05_13",test_float_05_13);
}

