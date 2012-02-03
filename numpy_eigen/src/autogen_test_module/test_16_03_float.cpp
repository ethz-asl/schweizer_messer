#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 16, 3> test_float_16_03(const Eigen::Matrix<float, 16, 3> & M)
{
	return M;
}
void export_float_16_03()
{
	boost::python::def("test_float_16_03",test_float_16_03);
}

