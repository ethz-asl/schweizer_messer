#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 11, 1> test_int_11_01(const Eigen::Matrix<int, 11, 1> & M)
{
	return M;
}
void export_int_11_01()
{
	boost::python::def("test_int_11_01",test_int_11_01);
}

