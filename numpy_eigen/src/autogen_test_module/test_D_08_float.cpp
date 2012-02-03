#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 8> test_float_D_08(const Eigen::Matrix<float, Eigen::Dynamic, 8> & M)
{
	return M;
}
void export_float_D_08()
{
	boost::python::def("test_float_D_08",test_float_D_08);
}

