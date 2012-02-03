#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 15> test_float_05_15(const Eigen::Matrix<float, 5, 15> & M)
{
	return M;
}
void export_float_05_15()
{
	boost::python::def("test_float_05_15",test_float_05_15);
}

