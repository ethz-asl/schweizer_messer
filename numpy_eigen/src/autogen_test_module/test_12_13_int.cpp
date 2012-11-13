#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 12, 13> test_int_12_13(const Eigen::Matrix<int, 12, 13> & M)
{
	return M;
}
void export_int_12_13()
{
	boost::python::def("test_int_12_13",test_int_12_13);
}

