#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 10, 5> test_float_10_05(const Eigen::Matrix<float, 10, 5> & M)
{
	return M;
}
void export_float_10_05()
{
	boost::python::def("test_float_10_05",test_float_10_05);
}

