#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 12, 5> test_float_12_05(const Eigen::Matrix<float, 12, 5> & M)
{
	return M;
}
void export_float_12_05()
{
	boost::python::def("test_float_12_05",test_float_12_05);
}

