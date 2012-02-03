#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 8> test_float_03_08(const Eigen::Matrix<float, 3, 8> & M)
{
	return M;
}
void export_float_03_08()
{
	boost::python::def("test_float_03_08",test_float_03_08);
}

