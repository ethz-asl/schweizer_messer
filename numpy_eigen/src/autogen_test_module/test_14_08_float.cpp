#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 14, 8> test_float_14_08(const Eigen::Matrix<float, 14, 8> & M)
{
	return M;
}
void export_float_14_08()
{
	boost::python::def("test_float_14_08",test_float_14_08);
}

