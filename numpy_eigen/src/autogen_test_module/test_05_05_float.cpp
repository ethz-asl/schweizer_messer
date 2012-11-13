#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 5> test_float_05_05(const Eigen::Matrix<float, 5, 5> & M)
{
	return M;
}
void export_float_05_05()
{
	boost::python::def("test_float_05_05",test_float_05_05);
}

