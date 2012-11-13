#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 2, 9> test_int_02_09(const Eigen::Matrix<int, 2, 9> & M)
{
	return M;
}
void export_int_02_09()
{
	boost::python::def("test_int_02_09",test_int_02_09);
}

