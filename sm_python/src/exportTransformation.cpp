#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/kinematics/Transformation.hpp>
#include <sm/kinematics/UncertainTransformation.hpp>
#include <sm/boost/serialization.hpp>
#include <sm/python/boost_serialization_pickle.hpp>

template<typename T>
void loadobj( T * obj, std::string fname) {
    sm::boost_serialization::load( *obj, fname );
}

template<typename T>
void saveobj( T * obj, std::string fname) {
    sm::boost_serialization::save( *obj, fname );
}

void exportTransformation()
{
  using namespace sm::kinematics;
  using namespace boost::python;
  void (Transformation::*setRandom1)() = &Transformation::setRandom;
  void (Transformation::*setRandom2)( double , double ) = &Transformation::setRandom;

  def("interpolateTransformations", &interpolateTransformations);
  def("slerpTransformations", &slerpTransformations);


  class_<Transformation, boost::shared_ptr<Transformation> >("Transformation", init<>())
    .def(init<const Eigen::Matrix4d &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d>())
      .def("save", &saveobj<Transformation>)
      .def("load", &loadobj<Transformation>)
    .def("T", &Transformation::T)
    .def("C", &Transformation::C)
      .def("t", &Transformation::t, return_value_policy<copy_const_reference>())
      .def("q", &Transformation::q, return_value_policy<copy_const_reference>())
    .def("T3x4", &Transformation::T3x4)
    .def("inverse", &Transformation::inverse)
    .def("setIdentity", &Transformation::setIdentity)
    .def("setRandom", setRandom1)
    .def("setRandom", setRandom2)
    .def(self * UncertainTransformation())
    .def(self * self)
    .def(self * UncertainHomogeneousPoint())
    .def(self * HomogeneousPoint())
    //.def(self * Eigen::Vector3d())
    //.def(self * Eigen::Vector4d())
    .def("checkTransformationIsValid", &Transformation::checkTransformationIsValid)
    .def("S", &Transformation::S)
      .def_pickle( sm::python::pickle_suite<Transformation>() )
      ;

  typedef UncertainTransformation::covariance_t covariance_t;

  class_<UncertainTransformation, boost::shared_ptr<UncertainTransformation> >("UncertainTransformation", init<>())
    .def(init<const Eigen::Matrix4d &, const covariance_t & >())
    .def(init<const Eigen::Matrix4d &, double, double>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d, const covariance_t &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d, double, double>())
    .def(init<const Transformation &, const covariance_t &>())
    .def(init<const Transformation &, double, double>())
    .def(init<const Transformation &>())
    .def(init<const Eigen::Matrix4d &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d>())
      .def("save", &saveobj<UncertainTransformation>)
      .def("load", &loadobj<UncertainTransformation>)
    .def(self * self)
    .def(self * UncertainHomogeneousPoint())
    .def(self * HomogeneousPoint())
    .def(self * Transformation())
    //.def(self * Eigen::Vector3d())
    //.def(self * Eigen::Vector4d())
    .def("inverse",&UncertainTransformation::inverse)
    .def("U", &UncertainTransformation::U, return_value_policy<copy_const_reference>())
    .def("setU", &UncertainTransformation::setU)
    .def("setUOplus", &UncertainTransformation::setUOplus)
    .def("T", &Transformation::T)
    .def("C", &Transformation::C)
    .def("t", &Transformation::t, return_value_policy<copy_const_reference>())
    .def("q", &Transformation::q, return_value_policy<copy_const_reference>())
    .def("T3x4", &Transformation::T3x4)
    .def("inverse", &Transformation::inverse)
    .def("setIdentity", &Transformation::setIdentity)
    .def("setRandom", setRandom1)
    .def("setRandom", setRandom2)
    .def("S", &Transformation::S)

    ;

}
