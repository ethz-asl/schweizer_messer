#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 6, 1> test_int_06_01(const Eigen::Matrix<int, 6, 1> & M)
{
	return M;
}
void export_int_06_01()
{
	boost::python::def("test_int_06_01",test_int_06_01);
}

