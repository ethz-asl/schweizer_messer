#include <Eigen/Core>

#include <numpy_eigen/boost_python_headers.hpp>
Eigen::Matrix<float, 8, 3> test_float_08_03(const Eigen::Matrix<float, 8, 3> & M)
{
	return M;
}
void export_float_08_03()
{
	boost::python::def("test_float_08_03",test_float_08_03);
}

