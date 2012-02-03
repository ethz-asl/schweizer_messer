#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 11, 8> test_double_11_08(const Eigen::Matrix<double, 11, 8> & M)
{
	return M;
}
void export_double_11_08()
{
	boost::python::def("test_double_11_08",test_double_11_08);
}

