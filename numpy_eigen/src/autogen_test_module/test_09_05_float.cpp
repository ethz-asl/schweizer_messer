#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 9, 5> test_float_09_05(const Eigen::Matrix<float, 9, 5> & M)
{
	return M;
}
void export_float_09_05()
{
	boost::python::def("test_float_09_05",test_float_09_05);
}

