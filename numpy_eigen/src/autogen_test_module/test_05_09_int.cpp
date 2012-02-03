#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<int, 5, 9> test_int_05_09(const Eigen::Matrix<int, 5, 9> & M)
{
	return M;
}
void export_int_05_09()
{
	boost::python::def("test_int_05_09",test_int_05_09);
}

