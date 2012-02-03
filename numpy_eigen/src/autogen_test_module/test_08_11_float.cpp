#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 11> test_float_08_11(const Eigen::Matrix<float, 8, 11> & M)
{
	return M;
}
void export_float_08_11()
{
	boost::python::def("test_float_08_11",test_float_08_11);
}

