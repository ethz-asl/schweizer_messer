#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, Eigen::Dynamic> test_int_08_D(const Eigen::Matrix<int, 8, Eigen::Dynamic> & M)
{
	return M;
}
void export_int_08_D()
{
	boost::python::def("test_int_08_D",test_int_08_D);
}

