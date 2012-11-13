#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 13, 8> test_int_13_08(const Eigen::Matrix<int, 13, 8> & M)
{
	return M;
}
void export_int_13_08()
{
	boost::python::def("test_int_13_08",test_int_13_08);
}

