#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 8, 4> test_int_08_04(const Eigen::Matrix<int, 8, 4> & M)
{
	return M;
}
void export_int_08_04()
{
	boost::python::def("test_int_08_04",test_int_08_04);
}

