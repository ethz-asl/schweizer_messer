#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 12> test_float_08_12(const Eigen::Matrix<float, 8, 12> & M)
{
	return M;
}
void export_float_08_12()
{
	boost::python::def("test_float_08_12",test_float_08_12);
}

