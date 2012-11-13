#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 7> test_int_12_07(const Eigen::Matrix<int, 12, 7> & M)
{
	return M;
}
void export_int_12_07()
{
	boost::python::def("test_int_12_07",test_int_12_07);
}

