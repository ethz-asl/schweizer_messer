#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, 1> test_int_04_01(const Eigen::Matrix<int, 4, 1> & M)
{
	return M;
}
void export_int_04_01()
{
	boost::python::def("test_int_04_01",test_int_04_01);
}

