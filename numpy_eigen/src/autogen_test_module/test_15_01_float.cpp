#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 15, 1> test_float_15_01(const Eigen::Matrix<float, 15, 1> & M)
{
	return M;
}
void export_float_15_01()
{
	boost::python::def("test_float_15_01",test_float_15_01);
}

