#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 10, 4> test_int_10_04(const Eigen::Matrix<int, 10, 4> & M)
{
	return M;
}
void export_int_10_04()
{
	boost::python::def("test_int_10_04",test_int_10_04);
}

