#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 4, 10> test_float_04_10(const Eigen::Matrix<float, 4, 10> & M)
{
	return M;
}
void export_float_04_10()
{
	boost::python::def("test_float_04_10",test_float_04_10);
}

