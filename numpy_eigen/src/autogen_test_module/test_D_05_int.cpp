#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 5> test_int_D_05(const Eigen::Matrix<int, Eigen::Dynamic, 5> & M)
{
	return M;
}
void export_int_D_05()
{
	boost::python::def("test_int_D_05",test_int_D_05);
}

