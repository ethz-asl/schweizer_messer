#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 15> test_float_03_15(const Eigen::Matrix<float, 3, 15> & M)
{
	return M;
}
void export_float_03_15()
{
	boost::python::def("test_float_03_15",test_float_03_15);
}

