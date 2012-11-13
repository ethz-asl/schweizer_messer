#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, 14> test_int_08_14(const Eigen::Matrix<int, 8, 14> & M)
{
	return M;
}
void export_int_08_14()
{
	boost::python::def("test_int_08_14",test_int_08_14);
}

