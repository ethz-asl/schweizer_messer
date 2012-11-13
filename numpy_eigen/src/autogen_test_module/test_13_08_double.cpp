#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 13, 8> test_double_13_08(const Eigen::Matrix<double, 13, 8> & M)
{
	return M;
}
void export_double_13_08()
{
	boost::python::def("test_double_13_08",test_double_13_08);
}

