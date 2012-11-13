#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 13, 8> test_float_13_08(const Eigen::Matrix<float, 13, 8> & M)
{
	return M;
}
void export_float_13_08()
{
	boost::python::def("test_float_13_08",test_float_13_08);
}

