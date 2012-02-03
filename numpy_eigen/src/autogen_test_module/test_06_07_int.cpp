#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 7> test_int_06_07(const Eigen::Matrix<int, 6, 7> & M)
{
	return M;
}
void export_int_06_07()
{
	boost::python::def("test_int_06_07",test_int_06_07);
}

