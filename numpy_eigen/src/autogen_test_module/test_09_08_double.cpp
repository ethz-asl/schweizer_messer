#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 9, 8> test_double_09_08(const Eigen::Matrix<double, 9, 8> & M)
{
	return M;
}
void export_double_09_08()
{
	boost::python::def("test_double_09_08",test_double_09_08);
}

