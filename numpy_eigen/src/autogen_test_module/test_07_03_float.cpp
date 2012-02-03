#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 7, 3> test_float_07_03(const Eigen::Matrix<float, 7, 3> & M)
{
	return M;
}
void export_float_07_03()
{
	boost::python::def("test_float_07_03",test_float_07_03);
}

