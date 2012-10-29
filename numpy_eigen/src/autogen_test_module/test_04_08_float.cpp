#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 8> test_float_04_08(const Eigen::Matrix<float, 4, 8> & M)
{
	return M;
}
void export_float_04_08()
{
	boost::python::def("test_float_04_08",test_float_04_08);
}

