#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, Eigen::Dynamic> test_int_11_D(const Eigen::Matrix<int, 11, Eigen::Dynamic> & M)
{
	return M;
}
void export_int_11_D()
{
	boost::python::def("test_int_11_D",test_int_11_D);
}

