#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/kinematics/Transformation.hpp>
#include <sm/kinematics/UncertainTransformation.hpp>

void exportTransformation()
{
  using namespace sm::kinematics;
  using namespace boost::python;
  void (Transformation::*setRandom1)() = &Transformation::setRandom;
  void (Transformation::*setRandom2)( double , double ) = &Transformation::setRandom;


  class_<Transformation, boost::shared_ptr<Transformation> >("Transformation", init<>())
    .def(init<const Eigen::Matrix4d &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d>())
    .def("T", &Transformation::T)
    .def("C", &Transformation::T)
    .def("t", &Transformation::T)
    .def("q", &Transformation::T)
    .def("T3x4", &Transformation::T)
    .def("inverse", &Transformation::T)
    .def("setIdentity", &Transformation::T)
    .def("setRandom", setRandom1)
    .def("setRandom", setRandom2)
    .def(self * self)
    .def(self * Eigen::Vector3d())
    .def(self * Eigen::Vector4d())
    .def(self * HomogeneousPoint())
    .def("checkTransformationIsValid", &Transformation::checkTransformationIsValid)
    .def("S", &Transformation::S)
    ;

  typedef UncertainTransformation::covariance_t covariance_t;

  class_<UncertainTransformation, boost::shared_ptr<UncertainTransformation>, bases<Transformation> >("UncertainTransformation", init<>())
    .def(init<const Eigen::Matrix4d &, const covariance_t & >())
    .def(init<const Eigen::Matrix4d &, double, double>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d, const covariance_t &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d, double, double>())
    .def(init<const Transformation &, const covariance_t &>())
    .def(init<const Transformation &, double, double>())
    .def(init<const Transformation &>())
    .def(init<const Eigen::Matrix4d &>())
    .def(init<const Eigen::Vector4d &, const Eigen::Vector3d>())
    .def(self * self)
    .def(self * Transformation())
    .def(self * Eigen::Vector3d())
    .def(self * Eigen::Vector4d())
    .def(self * HomogeneousPoint())
    .def(self * UncertainHomogeneousPoint())
    .def("inverse",&UncertainTransformation::inverse)
    .def("U", &UncertainTransformation::U, return_value_policy<copy_const_reference>())
    .def("setU", &UncertainTransformation::setU)
    .def("setUOplus", &UncertainTransformation::setUOplus)
    ;

}
