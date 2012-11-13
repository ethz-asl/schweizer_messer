#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 12, 8> test_double_12_08(const Eigen::Matrix<double, 12, 8> & M)
{
	return M;
}
void export_double_12_08()
{
	boost::python::def("test_double_12_08",test_double_12_08);
}

