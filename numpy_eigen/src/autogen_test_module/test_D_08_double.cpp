#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<double, Eigen::Dynamic, 8> test_double_D_08(const Eigen::Matrix<double, Eigen::Dynamic, 8> & M)
{
	return M;
}
void export_double_D_08()
{
	boost::python::def("test_double_D_08",test_double_D_08);
}

