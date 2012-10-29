#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, 8> test_int_08_08(const Eigen::Matrix<int, 8, 8> & M)
{
	return M;
}
void export_int_08_08()
{
	boost::python::def("test_int_08_08",test_int_08_08);
}

