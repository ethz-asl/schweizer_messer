#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, Eigen::Dynamic> test_int_14_D(const Eigen::Matrix<int, 14, Eigen::Dynamic> & M)
{
	return M;
}
void export_int_14_D()
{
	boost::python::def("test_int_14_D",test_int_14_D);
}

