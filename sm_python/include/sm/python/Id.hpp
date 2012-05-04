#ifndef SM_PYTHON_ID_HPP
#define SM_PYTHON_ID_HPP

#include <numpy_eigen/boost_python_headers.hpp>
#include <boost/python/to_python_converter.hpp>
#include <Python.h>
#include <boost/cstdint.hpp>

namespace sm { namespace python {


    // adapted from http://misspent.wordpress.com/2009/09/27/how-to-write-boost-python-converters/
    
    template<typename ID_T>
    struct Id_python_converter
    {
      typedef ID_T id_t;

      // The "Convert from C to Python" API
      static PyObject * convert(id_t const & id){
	PyObject * i = PyInt_FromLong(id.getId());
	return boost::python::incref(i);
      }
      
      // The "Convert from Python to C" API
      // Two functions: convertible() and construct()
      static void * convertible(PyObject* obj_ptr)
      {
	if (!PyInt_Check(obj_ptr)) 
	  return 0;
    
	return obj_ptr;
      }

      static void construct(
			    PyObject* obj_ptr,
			    boost::python::converter::rvalue_from_python_stage1_data* data)
      {

	// Get the value.
	boost::uint64_t value = PyInt_AS_LONG(obj_ptr);
    
    
	void* storage = ((boost::python::converter::rvalue_from_python_storage<id_t>*)
			 data)->storage.bytes;
    

	new (storage) id_t(value);
    
	// Stash the memory chunk pointer for later use by boost.python
	data->convertible = storage;
      }
  



      // The registration function.
      static void register_converter()
      {
	boost::python::to_python_converter<id_t,Id_python_converter>();
	boost::python::converter::registry::push_back(
						      &convertible,
						      &construct,
						      boost::python::type_id<id_t>());

      }
  
    };

  }}

#endif /* SM_PYTHON_ID_HPP */
