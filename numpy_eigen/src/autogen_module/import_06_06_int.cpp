// This file automatically generated by create_export_module.py
#include "../NumpyEigenConverter.hpp"


void import_06_06_int()
{
	// Without this import, the converter will segfault
	import_array();
	NumpyEigenConverter<Eigen::Matrix< int, 6, 6 > >::register_converter();
}
