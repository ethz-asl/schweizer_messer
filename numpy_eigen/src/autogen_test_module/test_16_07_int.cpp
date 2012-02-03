#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 16, 7> test_int_16_07(const Eigen::Matrix<int, 16, 7> & M)
{
	return M;
}
void export_int_16_07()
{
	boost::python::def("test_int_16_07",test_int_16_07);
}

