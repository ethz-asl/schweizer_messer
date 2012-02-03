#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 13> test_int_03_13(const Eigen::Matrix<int, 3, 13> & M)
{
	return M;
}
void export_int_03_13()
{
	boost::python::def("test_int_03_13",test_int_03_13);
}

