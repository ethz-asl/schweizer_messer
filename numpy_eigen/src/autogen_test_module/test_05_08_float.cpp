#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 8> test_float_05_08(const Eigen::Matrix<float, 5, 8> & M)
{
	return M;
}
void export_float_05_08()
{
	boost::python::def("test_float_05_08",test_float_05_08);
}

