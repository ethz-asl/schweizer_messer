#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 3, 8> test_double_03_08(const Eigen::Matrix<double, 3, 8> & M)
{
	return M;
}
void export_double_03_08()
{
	boost::python::def("test_double_03_08",test_double_03_08);
}

