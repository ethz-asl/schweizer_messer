#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/timing/TimestampCorrector.hpp>
#include <boost/cstdint.hpp>

template<typename TIME_T>
void exportTimestampCorrector(const std::string & className)
{
  using namespace boost::python;
  using namespace sm::timing;
  
  typedef typename TimestampCorrector<TIME_T>::time_t time_t;

  class_< TimestampCorrector<TIME_T> >( className.c_str(), init<>() )
    .def("correctTimestamp", (time_t (TimestampCorrector<TIME_T>::*) (const time_t&, const time_t&))&TimestampCorrector<TIME_T>::correctTimestamp, "correctedEventLocalTime = correctTimestamp(eventRemoteTime, eventLocalTimes).\nNote: This function must be called with monotonically increasing remote timestamps.")
    .def("correctTimestampPeriodic", (time_t (TimestampCorrector<TIME_T>::*) (const time_t&, const time_t&, const time_t&))&TimestampCorrector<TIME_T>::correctTimestamp, "correctedEventLocalTime = correctTimestamp(eventRemoteTime, eventLocalTimes, switchingPeriod).\nNote: This function must be called with monotonically increasing remote timestamps.")
    .def("getLocalTime", &TimestampCorrector<TIME_T>::getLocalTime, "eventLocalTime = getLocalTime(eventRemoteTime)")
    .def("convexHullSize", &TimestampCorrector<TIME_T>::convexHullSize)
    .def("printHullPoints", &TimestampCorrector<TIME_T>::printHullPoints)
      .def("getSlope", &TimestampCorrector<TIME_T>::getSlope)
      .def("getOffset", &TimestampCorrector<TIME_T>::getOffset)
    ;

}


void exportTimestampCorrectors()
{
  exportTimestampCorrector<double>("DoubleTimestampCorrector");
  exportTimestampCorrector<boost::int64_t>("LongTimestampCorrector");
}
