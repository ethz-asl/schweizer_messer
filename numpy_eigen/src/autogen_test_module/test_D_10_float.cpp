#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, Eigen::Dynamic, 10> test_float_D_10(const Eigen::Matrix<float, Eigen::Dynamic, 10> & M)
{
	return M;
}
void export_float_D_10()
{
	boost::python::def("test_float_D_10",test_float_D_10);
}

