#ifndef SM_BOOST_NULL_DELETER_HPP
#define SM_BOOST_NULL_DELETER_HPP

namespace sm {
  namespace boost {

    struct null_deleter
    {
      template<typename T>
      void operator()(const T * ){}
    };

  } // namespace boost
} // namespace sm


#endif /* SM_BOOST_NULL_DELETER_HPP */
