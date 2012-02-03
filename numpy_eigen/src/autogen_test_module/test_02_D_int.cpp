#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, Eigen::Dynamic> test_int_02_D(const Eigen::Matrix<int, 2, Eigen::Dynamic> & M)
{
	return M;
}
void export_int_02_D()
{
	boost::python::def("test_int_02_D",test_int_02_D);
}

