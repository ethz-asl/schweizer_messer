/**
 * @file   serialization_macros.hpp
 * @author Simon Lynen <simon.lynen@mavt.ethz.ch>
 * @date   Thu May 22 02:55:13 2013
 *
 * @brief  Comparison macros to facilitate checking in serialization methods.
 *
 *
 */

#ifndef SM_SERIALIZATION_MACROS_HPP
#define SM_SERIALIZATION_MACROS_HPP

#include <type_traits>
#include <sstream>
#include <ostream>
#include <boost/static_assert.hpp>
#include <boost/shared_ptr.hpp>

namespace {
namespace {
typedef char yes;
typedef int no;

struct AnyT {
  template<class T> AnyT(const T &);
};

no operator <<(const AnyT &, const AnyT &);

template<class T> yes check(const T&);
no check(no);
}

//this template metaprogramming struct can tell us if there is the operator<< defined somewhere
template<typename StreamType, typename T>
class HasOStreamOperator {
  static StreamType & stream;
  static T & x;
 public:
  enum {
    value = sizeof(check(stream << x)) == sizeof(yes)
  };
};
template<typename StreamType, typename T>
class HasOStreamOperator<StreamType, boost::shared_ptr<T> > {
 public:
  enum {
     value = HasOStreamOperator<StreamType, T>::value
   };
};
template<typename StreamType, typename T>
class HasOStreamOperator<StreamType, T* > {
 public:
  enum {
     value = HasOStreamOperator<StreamType, T>::value
   };
};

//this template metaprogramming struct can tell us whether a class has a member
//function isBinaryEqual
template<typename T>
class HasIsBinaryEqual {
  template<typename U, bool (U::*)(const T&) const> struct Check;
  template<typename U> static char func(Check<U, &U::isBinaryEqual> *);
  template<typename U> static int func(...);
 public:
  enum {
    value = (sizeof(func<T>(0)) == sizeof(char))
  };
};
template<typename T>
class HasIsBinaryEqual<boost::shared_ptr<T> > {
 public:
  enum {
    value = HasIsBinaryEqual<T>::value
  };
};
template<typename T>
class HasIsBinaryEqual<T*> {
 public:
  enum {
    value = HasIsBinaryEqual<T>::value
  };
};

//these structs are used to choose between isBinaryEqual function call and the
//default operator==
template<bool, typename A>
struct isSame;

template<typename A>
struct isSame<true, A> {
  static bool eval(const A& lhs, const A& rhs) {
    return lhs.isBinaryEqual(rhs);
  }
};

template<typename A>
struct isSame<true, boost::shared_ptr<A> > {
  static bool eval(const boost::shared_ptr<A>& lhs, const boost::shared_ptr<A>& rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    return lhs->isBinaryEqual(*rhs);
  }
};

template<typename A>
struct isSame<true, A* > {
  static bool eval(const A* const lhs, const A* const rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    return lhs->isBinaryEqual(*rhs);
  }
};

template<typename A>
struct isSame<false, A> {
  static bool eval(const A& lhs, const A& rhs) {
    return lhs == rhs;
  }
};

template<typename A>
struct isSame<false, A*> {
  static bool eval(A const * lhs, A const * rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    return *lhs == *rhs;
  }
};

template<typename A>
struct isSame<false, boost::shared_ptr<A> > {
  static bool eval(const boost::shared_ptr<A>& lhs, const boost::shared_ptr<A>& rhs) {
    if (!lhs && !rhs) {
      return true;
    }
    if (!lhs || !rhs) {
      return false;
    }
    return *lhs == *rhs;
  }
};

//if the object supports it stream to ostream, otherwise put NA
template<bool, typename A>
struct streamIf;

template<typename A>
struct streamIf<true, A> {
  static std::string eval(const A& rhs) {
    std::stringstream ss;
    ss << rhs;
    return ss.str();
  }
};

template<typename A>
struct streamIf<true, A*> {
  static std::string eval(const A* rhs) {
    if (!rhs) {
      return "NULL";
    }
    std::stringstream ss;
    ss << *rhs;
    return ss.str();
  }
};

template<typename A>
struct streamIf<true, boost::shared_ptr<A> > {
  static std::string eval(const boost::shared_ptr<A>& rhs) {
    if (!rhs) {
      return "NULL";
    }
    std::stringstream ss;
    ss << *rhs;
    return ss.str();
  }
};

template<typename A>
struct streamIf<true, boost::shared_ptr<const A> > {
  static std::string eval(const boost::shared_ptr<const A>& rhs) {
    if (!rhs) {
      return "NULL";
    }
    std::stringstream ss;
    ss << *rhs;
    return ss.str();
  }
};

template<typename A>
struct streamIf<false, A> {
  static std::string eval(const A&) {
    return "NA";
  }
};
}

//these defines set the default behaviour if no verbosity argument is given
#define SM_SERIALIZATION_CHECKSAME_VERBOSE(THIS, OTHER) SM_SERIALIZATION_CHECKSAME_IMPL(THIS, OTHER, true)
#define SM_SERIALIZATION_CHECKMEMBERSSAME_VERBOSE(OTHER, MEMBER) SM_SERIALIZATION_CHECKMEMBERSSAME_IMPL(OTHER, MEMBER, true)

#define SM_SERIALIZATION_CHECKSAME_IMPL(THIS, OTHER, VERBOSE) \
    (isSame<HasIsBinaryEqual<decltype(OTHER)>::value, decltype(OTHER) >::eval(THIS, OTHER)) ? true :\
        (VERBOSE ? (std::cout <<  "*** Validation failed on " << #OTHER << ": "<< \
            streamIf<HasOStreamOperator<std::ostream, decltype(OTHER)>::value, decltype(OTHER) >::eval(THIS) << \
            " other " << streamIf<HasOStreamOperator<std::ostream, decltype(OTHER)>::value, decltype(OTHER)>::eval(OTHER) \
            << " at " << __PRETTY_FUNCTION__ << \
            " In: " << __FILE__ << ":" << __LINE__ << std::endl << std::endl) && false : false)

#define SM_SERIALIZATION_CHECKMEMBERSSAME_IMPL(OTHER, MEMBER, VERBOSE) \
    (isSame<HasIsBinaryEqual<decltype(MEMBER)>::value, decltype(MEMBER) >::eval(this->MEMBER, OTHER.MEMBER)) ? true :\
        (VERBOSE ? (std::cout <<  "*** Validation failed on " << #MEMBER << ": "<< \
            streamIf<HasOStreamOperator<std::ostream, decltype(MEMBER)>::value, decltype(MEMBER) >::eval(this->MEMBER) << \
            " other " << streamIf<HasOStreamOperator<std::ostream, decltype(MEMBER)>::value, decltype(MEMBER) >::eval(OTHER.MEMBER) \
            << " at " << __PRETTY_FUNCTION__ << \
            " In: " << __FILE__ << ":" << __LINE__ << std::endl << std::endl) && false : false)

//this is some internal default macro parameter deduction
#define SM_SERIALIZATION_GET_3RD_ARG(arg1, arg2, arg3, ...) arg3
#define SM_SERIALIZATION_GET_4TH_ARG(arg1, arg2, arg3, arg4, ...) arg4

#define SM_SERIALIZATION_MACRO_CHOOSER_MEMBER_SAME(...) \
    SM_SERIALIZATION_GET_4TH_ARG(__VA_ARGS__, SM_SERIALIZATION_CHECKMEMBERSSAME_IMPL,  SM_SERIALIZATION_CHECKMEMBERSSAME_VERBOSE )
#define SM_SERIALIZATION_MACRO_CHOOSER_SAME(...) \
    SM_SERIALIZATION_GET_4TH_ARG(__VA_ARGS__, SM_SERIALIZATION_CHECKSAME_IMPL,  SM_SERIALIZATION_CHECKSAME_VERBOSE )

//\brief This macro checks this->MEMBER against OTHER.MEMBER  with the appropriate IsBinaryEqual or operator==.
//Pointers and boost::shared_ptr are handled automatically
#define SM_CHECKMEMBERSSAME(...) SM_SERIALIZATION_MACRO_CHOOSER_MEMBER_SAME(__VA_ARGS__)(__VA_ARGS__)

//\brief This macro checks THIS against OTHER with the appropriate IsBinaryEqual or operator==.
//Pointers and boost::shared_ptr are handled automatically
#define SM_CHECKSAME(...) SM_SERIALIZATION_MACRO_CHOOSER_SAME(__VA_ARGS__)(__VA_ARGS__)

#endif //SM_SERIALIZATION_MACROS_HPP
