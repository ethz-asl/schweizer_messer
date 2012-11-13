#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 1> test_int_03_01(const Eigen::Matrix<int, 3, 1> & M)
{
	return M;
}
void export_int_03_01()
{
	boost::python::def("test_int_03_01",test_int_03_01);
}

