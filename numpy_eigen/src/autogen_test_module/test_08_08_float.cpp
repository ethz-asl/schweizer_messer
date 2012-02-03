#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 8> test_float_08_08(const Eigen::Matrix<float, 8, 8> & M)
{
	return M;
}
void export_float_08_08()
{
	boost::python::def("test_float_08_08",test_float_08_08);
}

