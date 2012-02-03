#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 11> test_float_03_11(const Eigen::Matrix<float, 3, 11> & M)
{
	return M;
}
void export_float_03_11()
{
	boost::python::def("test_float_03_11",test_float_03_11);
}

