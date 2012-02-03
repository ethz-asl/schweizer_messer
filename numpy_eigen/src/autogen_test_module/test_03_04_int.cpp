#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 4> test_int_03_04(const Eigen::Matrix<int, 3, 4> & M)
{
	return M;
}
void export_int_03_04()
{
	boost::python::def("test_int_03_04",test_int_03_04);
}

