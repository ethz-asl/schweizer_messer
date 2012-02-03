#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 6, 8> test_float_06_08(const Eigen::Matrix<float, 6, 8> & M)
{
	return M;
}
void export_float_06_08()
{
	boost::python::def("test_float_06_08",test_float_06_08);
}

