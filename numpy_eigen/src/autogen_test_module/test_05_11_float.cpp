#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 11> test_float_05_11(const Eigen::Matrix<float, 5, 11> & M)
{
	return M;
}
void export_float_05_11()
{
	boost::python::def("test_float_05_11",test_float_05_11);
}

