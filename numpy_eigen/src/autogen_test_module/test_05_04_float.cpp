#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 5, 4> test_float_05_04(const Eigen::Matrix<float, 5, 4> & M)
{
	return M;
}
void export_float_05_04()
{
	boost::python::def("test_float_05_04",test_float_05_04);
}

