#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 16, 2> test_int_16_02(const Eigen::Matrix<int, 16, 2> & M)
{
	return M;
}
void export_int_16_02()
{
	boost::python::def("test_int_16_02",test_int_16_02);
}

