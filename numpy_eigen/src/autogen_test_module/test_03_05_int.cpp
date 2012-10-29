#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 3, 5> test_int_03_05(const Eigen::Matrix<int, 3, 5> & M)
{
	return M;
}
void export_int_03_05()
{
	boost::python::def("test_int_03_05",test_int_03_05);
}

