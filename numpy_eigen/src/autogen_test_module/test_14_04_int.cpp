#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 14, 4> test_int_14_04(const Eigen::Matrix<int, 14, 4> & M)
{
	return M;
}
void export_int_14_04()
{
	boost::python::def("test_int_14_04",test_int_14_04);
}

