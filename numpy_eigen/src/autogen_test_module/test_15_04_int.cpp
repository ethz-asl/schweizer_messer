#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 4> test_int_15_04(const Eigen::Matrix<int, 15, 4> & M)
{
	return M;
}
void export_int_15_04()
{
	boost::python::def("test_int_15_04",test_int_15_04);
}

