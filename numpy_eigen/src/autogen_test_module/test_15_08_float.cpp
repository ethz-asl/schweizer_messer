#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 8> test_float_15_08(const Eigen::Matrix<float, 15, 8> & M)
{
	return M;
}
void export_float_15_08()
{
	boost::python::def("test_float_15_08",test_float_15_08);
}

