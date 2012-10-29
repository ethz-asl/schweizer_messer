#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 3, 10> test_float_03_10(const Eigen::Matrix<float, 3, 10> & M)
{
	return M;
}
void export_float_03_10()
{
	boost::python::def("test_float_03_10",test_float_03_10);
}

