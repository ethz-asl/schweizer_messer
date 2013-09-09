/*
 * NumericalComparison.hpp
 *
 *  Created on: Aug 13, 2013
 *      Author: Péter Fankhauser
 *	 Institute: ETH Zurich, Autonomous Systems Lab
 */

#ifndef NUMERICALCOMPARISON_HPP_
#define NUMERICALCOMPARISON_HPP_

using namespace std;

namespace sm {

/*
 * Compare floating point numbers within the precision of their datatypes.
 * Discussion at http://stackoverflow.com/questions/17333/most-effective-way-for-float-and-double-comparison
 */
class NumericalComparison
{
 public:

  /*!
   * Checks if two numbers a and b are equal within the precision of their datatype
   * @param a the first number to compare
   * @param b the second number to compare
   * @param epsilon the precision (precision of the datatype if not declared)
   * @return true if equal within precision of epsilon, false otherwise
   */
  template<typename ValueType_>
  static bool essentiallyEqual(const ValueType_ a, const ValueType_ b, ValueType_ epsilon = std::numeric_limits<ValueType_>::epsilon())
  {
    return fabs(a - b) <= ( (fabs(a) > fabs(b) ? fabs(b) : fabs(a)) * epsilon); // TODO in C++ only abs() necessary
  }

  /*!
   * Checks if a is greater than b (a > b) within the precision of their datatype
   * @param a the first number to compare
   * @param b the second number to compare
   * @param epsilon the precision (precision of the datatype if not declared)
   * @return true if a greater b within precision of epsilon, false otherwise
   */
  template<typename ValueType_>
  static bool definitelyGreaterThan(const ValueType_ a, const ValueType_ b, ValueType_ epsilon = std::numeric_limits<ValueType_>::epsilon())
  {
    return (a - b) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
  }

  /*!
   * Checks if a is less than b (a < b) within the precision of their datatype
   * @param a the first number to compare
   * @param b the second number to compare
   * @param epsilon the precision (precision of the datatype if not declared)
   * @return true if a less than b within precision of epsilon, false otherwise
   */
  template<typename ValueType_>
  static bool definitelyLessThan(const ValueType_ a, const ValueType_ b, ValueType_ epsilon = std::numeric_limits<ValueType_>::epsilon())
  {
    return (b - a) > ( (fabs(a) < fabs(b) ? fabs(b) : fabs(a)) * epsilon);
  }

  /*!
   * Checks if a is in between b and c (b < a < c) within the precision of their datatype
   * @param a the first number to compare
   * @param b the lower bound
   * @param c the upper bound
   * @param epsilon the precision (precision of the datatype if not declared)
   * @return true if a is in between b and c within precision of epsilon, false otherwise
   */
  template<typename ValueType_>
  static bool definitelyInBetween(const ValueType_ a, const ValueType_ b, const ValueType_ c, ValueType_ epsilon = std::numeric_limits<ValueType_>::epsilon())
  {
    return definitelyGreaterThan(a, b, epsilon) && definitelyLessThan(a, c, epsilon);
  }

};

} /* namespace sm */
#endif /* NUMERICALCOMPARISON_HPP_ */
