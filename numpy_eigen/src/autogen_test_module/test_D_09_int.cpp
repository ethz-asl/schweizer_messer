#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, Eigen::Dynamic, 9> test_int_D_09(const Eigen::Matrix<int, Eigen::Dynamic, 9> & M)
{
	return M;
}
void export_int_D_09()
{
	boost::python::def("test_int_D_09",test_int_D_09);
}

