#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, 8> test_int_11_08(const Eigen::Matrix<int, 11, 8> & M)
{
	return M;
}
void export_int_11_08()
{
	boost::python::def("test_int_11_08",test_int_11_08);
}

