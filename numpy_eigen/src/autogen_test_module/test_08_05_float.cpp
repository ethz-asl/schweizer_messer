#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 5> test_float_08_05(const Eigen::Matrix<float, 8, 5> & M)
{
	return M;
}
void export_float_08_05()
{
	boost::python::def("test_float_08_05",test_float_08_05);
}

