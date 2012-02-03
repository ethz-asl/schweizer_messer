#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 10> test_float_08_10(const Eigen::Matrix<float, 8, 10> & M)
{
	return M;
}
void export_float_08_10()
{
	boost::python::def("test_float_08_10",test_float_08_10);
}

