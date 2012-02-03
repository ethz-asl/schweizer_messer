#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 12> test_float_05_12(const Eigen::Matrix<float, 5, 12> & M)
{
	return M;
}
void export_float_05_12()
{
	boost::python::def("test_float_05_12",test_float_05_12);
}

