#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 12> test_int_D_12(const Eigen::Matrix<int, Eigen::Dynamic, 12> & M)
{
	return M;
}
void export_int_D_12()
{
	boost::python::def("test_int_D_12",test_int_D_12);
}

