#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 8> test_int_15_08(const Eigen::Matrix<int, 15, 8> & M)
{
	return M;
}
void export_int_15_08()
{
	boost::python::def("test_int_15_08",test_int_15_08);
}

