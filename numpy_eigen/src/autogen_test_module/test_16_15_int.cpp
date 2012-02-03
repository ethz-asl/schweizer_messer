#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 16, 15> test_int_16_15(const Eigen::Matrix<int, 16, 15> & M)
{
	return M;
}
void export_int_16_15()
{
	boost::python::def("test_int_16_15",test_int_16_15);
}

