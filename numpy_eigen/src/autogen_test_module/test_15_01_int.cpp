#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 15, 1> test_int_15_01(const Eigen::Matrix<int, 15, 1> & M)
{
	return M;
}
void export_int_15_01()
{
	boost::python::def("test_int_15_01",test_int_15_01);
}

