#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 15> test_float_02_15(const Eigen::Matrix<float, 2, 15> & M)
{
	return M;
}
void export_float_02_15()
{
	boost::python::def("test_float_02_15",test_float_02_15);
}

