#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 4> test_int_02_04(const Eigen::Matrix<int, 2, 4> & M)
{
	return M;
}
void export_int_02_04()
{
	boost::python::def("test_int_02_04",test_int_02_04);
}

