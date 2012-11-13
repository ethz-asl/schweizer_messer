#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 4> test_float_08_04(const Eigen::Matrix<float, 8, 4> & M)
{
	return M;
}
void export_float_08_04()
{
	boost::python::def("test_float_08_04",test_float_08_04);
}

