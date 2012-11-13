#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 5> test_int_15_05(const Eigen::Matrix<int, 15, 5> & M)
{
	return M;
}
void export_int_15_05()
{
	boost::python::def("test_int_15_05",test_int_15_05);
}

