#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, Eigen::Dynamic> test_int_04_D(const Eigen::Matrix<int, 4, Eigen::Dynamic> & M)
{
	return M;
}
void export_int_04_D()
{
	boost::python::def("test_int_04_D",test_int_04_D);
}

