#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 10> test_int_D_10(const Eigen::Matrix<int, Eigen::Dynamic, 10> & M)
{
	return M;
}
void export_int_D_10()
{
	boost::python::def("test_int_D_10",test_int_D_10);
}

