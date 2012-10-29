#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 4, 9> test_int_04_09(const Eigen::Matrix<int, 4, 9> & M)
{
	return M;
}
void export_int_04_09()
{
	boost::python::def("test_int_04_09",test_int_04_09);
}

