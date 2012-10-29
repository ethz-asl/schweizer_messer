#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 2, 5> test_float_02_05(const Eigen::Matrix<float, 2, 5> & M)
{
	return M;
}
void export_float_02_05()
{
	boost::python::def("test_float_02_05",test_float_02_05);
}

