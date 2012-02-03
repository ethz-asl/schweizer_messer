#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, 4, 8> test_double_04_08(const Eigen::Matrix<double, 4, 8> & M)
{
	return M;
}
void export_double_04_08()
{
	boost::python::def("test_double_04_08",test_double_04_08);
}

