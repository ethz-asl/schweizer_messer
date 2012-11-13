#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, 12> test_int_08_12(const Eigen::Matrix<int, 8, 12> & M)
{
	return M;
}
void export_int_08_12()
{
	boost::python::def("test_int_08_12",test_int_08_12);
}

