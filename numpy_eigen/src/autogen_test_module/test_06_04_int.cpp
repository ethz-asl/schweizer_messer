#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 4> test_int_06_04(const Eigen::Matrix<int, 6, 4> & M)
{
	return M;
}
void export_int_06_04()
{
	boost::python::def("test_int_06_04",test_int_06_04);
}

