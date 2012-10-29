#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 8> test_int_02_08(const Eigen::Matrix<int, 2, 8> & M)
{
	return M;
}
void export_int_02_08()
{
	boost::python::def("test_int_02_08",test_int_02_08);
}

