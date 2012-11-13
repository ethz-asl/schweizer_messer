#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 8> test_float_12_08(const Eigen::Matrix<float, 12, 8> & M)
{
	return M;
}
void export_float_12_08()
{
	boost::python::def("test_float_12_08",test_float_12_08);
}

