#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 12> test_int_12_12(const Eigen::Matrix<int, 12, 12> & M)
{
	return M;
}
void export_int_12_12()
{
	boost::python::def("test_int_12_12",test_int_12_12);
}

