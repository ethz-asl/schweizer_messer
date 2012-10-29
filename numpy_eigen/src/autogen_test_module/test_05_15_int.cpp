#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 5, 15> test_int_05_15(const Eigen::Matrix<int, 5, 15> & M)
{
	return M;
}
void export_int_05_15()
{
	boost::python::def("test_int_05_15",test_int_05_15);
}

