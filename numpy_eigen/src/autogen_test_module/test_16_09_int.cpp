#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 16, 9> test_int_16_09(const Eigen::Matrix<int, 16, 9> & M)
{
	return M;
}
void export_int_16_09()
{
	boost::python::def("test_int_16_09",test_int_16_09);
}

