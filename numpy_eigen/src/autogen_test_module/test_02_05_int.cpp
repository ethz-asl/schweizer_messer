#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 5> test_int_02_05(const Eigen::Matrix<int, 2, 5> & M)
{
	return M;
}
void export_int_02_05()
{
	boost::python::def("test_int_02_05",test_int_02_05);
}

