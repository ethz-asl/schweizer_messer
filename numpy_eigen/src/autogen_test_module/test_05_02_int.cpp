#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 5, 2> test_int_05_02(const Eigen::Matrix<int, 5, 2> & M)
{
	return M;
}
void export_int_05_02()
{
	boost::python::def("test_int_05_02",test_int_05_02);
}

