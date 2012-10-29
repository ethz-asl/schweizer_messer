#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, 8> test_float_07_08(const Eigen::Matrix<float, 7, 8> & M)
{
	return M;
}
void export_float_07_08()
{
	boost::python::def("test_float_07_08",test_float_07_08);
}

