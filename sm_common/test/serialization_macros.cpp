#include <cstdlib>
#include <boost/shared_ptr.hpp>
#include "gtest/gtest.h"
#include <sm/serialization_macros.hpp>

class SimpleEntry {
 private:
  int key_;
  double value_;
 public:
  void setRandom() {
    key_ = rand();
    value_ = static_cast<double>(rand()) / RAND_MAX;
  }
  bool operator==(const SimpleEntry& other) const {
    bool same = true;
    same = same && SM_CHECKMEMBERSSAME(other, key_);
    same = same && SM_CHECKMEMBERSSAME(other, value_);
    return same;
  }
  friend std::ostream& operator<<(std::ostream &os, const SimpleEntry& lhs);
};

std::ostream& operator<<(std::ostream &os, const SimpleEntry& lhs)
{
  os << lhs.key_ << " " << lhs.value_;
  return os;
}


class ComplexEntry {
 private:
  int key_;
  double value_;
  SimpleEntry* pSimple_;
  boost::shared_ptr<SimpleEntry> pSharedSimple_;

  bool operator==(const ComplexEntry& other) const;

 public:

  ComplexEntry(){
    key_ = 0;
    value_ = 0;
    pSimple_ = new SimpleEntry;
    pSharedSimple_.reset(new SimpleEntry);
  }

  ~ComplexEntry() {
    delete pSimple_;
    pSimple_ = NULL;
  }

  ComplexEntry(const ComplexEntry& rhs) {
    key_ = rhs.key_;
    value_ = rhs.value_;
    pSimple_ = new SimpleEntry(*rhs.pSimple_);
    pSharedSimple_.reset(new SimpleEntry(*rhs.pSharedSimple_));
  }

  ComplexEntry operator=(const ComplexEntry& rhs) {
    key_ = rhs.key_;
    value_ = rhs.value_;
    pSimple_ = new SimpleEntry(*rhs.pSimple_);
    pSharedSimple_.reset(new SimpleEntry(*rhs.pSharedSimple_));
    return *this;
  }

  void setRandom() {
    key_ = rand();
    value_ = static_cast<double>(rand()) / RAND_MAX;
    pSimple_->setRandom();
    pSharedSimple_->setRandom();
  }

  bool isBinaryEqual(const ComplexEntry& other) const {
    bool same = true;
    same = same && SM_CHECKMEMBERSSAME(other, key_);
    same = same && SM_CHECKMEMBERSSAME(other, value_);
    same = same && SM_CHECKMEMBERSSAME(other, pSimple_);
    same = same && SM_CHECKMEMBERSSAME(other, pSharedSimple_);
    return same;
  }
};

TEST(SerializationMacros, TestClassesComparisonWorks) {
  ComplexEntry e1, e2;
  e1.setRandom();
  e2.setRandom();

  ASSERT_TRUE(e1.isBinaryEqual(e1));
  ASSERT_FALSE(e1.isBinaryEqual(e2));
  ASSERT_FALSE(e2.isBinaryEqual(e1));
}


TEST(SerializationMacros, TestClassesMacroWorks) {
  ComplexEntry e1, e2;
  e1.setRandom();
  e2.setRandom();

  ASSERT_FALSE(SM_CHECKSAME(e1, e2));
  ASSERT_FALSE(SM_CHECKSAME(e2, e1));

  e2 = e1;

  ASSERT_TRUE(SM_CHECKSAME(e1, e2));
  ASSERT_TRUE(SM_CHECKSAME(e2, e1));

  ComplexEntry e3(e1);

  ASSERT_TRUE(SM_CHECKSAME(e1, e3));
  ASSERT_TRUE(SM_CHECKSAME(e3, e1));

}

TEST(SerializationMacros, TestClassesCopyCtorAssignWorks) {
  ComplexEntry e1, e2;
  e1.setRandom();
  e2.setRandom();

  ASSERT_TRUE(e1.isBinaryEqual(e1));
  ASSERT_FALSE(e1.isBinaryEqual(e2));
  ASSERT_FALSE(e2.isBinaryEqual(e1));

  e2 = e1;
  ASSERT_TRUE(e2.isBinaryEqual(e1));
  ASSERT_TRUE(e1.isBinaryEqual(e2));

  ComplexEntry e3(e1);
  ASSERT_TRUE(e3.isBinaryEqual(e1));
  ASSERT_TRUE(e1.isBinaryEqual(e3));

}

TEST(SerializationMacros, TestSharedPointer) {
  boost::shared_ptr<ComplexEntry> e1(new ComplexEntry);
  boost::shared_ptr<ComplexEntry> e2(new ComplexEntry);
  boost::shared_ptr<ComplexEntry> e3(new ComplexEntry);

  e1->setRandom();
  e2->setRandom();
  e3->setRandom();

  ASSERT_FALSE(SM_CHECKSAME(e1, e2));

  e1 = e2;

  ASSERT_TRUE(SM_CHECKSAME(e1, e2));

  boost::shared_ptr<ComplexEntry> e4(new ComplexEntry(*e1));

  ASSERT_TRUE(SM_CHECKSAME(e1, e4));
  ASSERT_TRUE(SM_CHECKSAME(e1, e4));
  ASSERT_FALSE(SM_CHECKSAME(e1, e3));
}

TEST(SerializationMacros, TestPointer) {
  ComplexEntry* e1 = new ComplexEntry;
  ComplexEntry* e2 = new ComplexEntry;
  ComplexEntry* e3 = new ComplexEntry;

  e1->setRandom();
  e2->setRandom();
  e3->setRandom();

  ASSERT_FALSE(SM_CHECKSAME(e1, e2));

  ComplexEntry* tmpe1 = e1;
  e1 = e2;

  ASSERT_TRUE(SM_CHECKSAME(e1, e2));

  ComplexEntry* e4 = new ComplexEntry(*e1);

  ASSERT_TRUE(SM_CHECKSAME(e1, e4));
  ASSERT_TRUE(SM_CHECKSAME(e1, e4));
  ASSERT_FALSE(SM_CHECKSAME(e1, e3));

  delete tmpe1;
  delete e2;
  delete e3;
  delete e4;
}


TEST(SerializationMacros, TestClassHasMethodDeduction) {
  ASSERT_EQ(HasIsBinaryEqual<ComplexEntry>::value, 1);
  ASSERT_EQ(HasIsBinaryEqual<SimpleEntry>::value, 0);
}

TEST(SerializationMacros, TestClassSharedPtrHasMethodDeduction) {
  typedef boost::shared_ptr<ComplexEntry> T1;
  typedef boost::shared_ptr<SimpleEntry> T2;
  ASSERT_EQ(HasIsBinaryEqual<T1>::value, 1);
  ASSERT_EQ(HasIsBinaryEqual<T2>::value, 0);
}

TEST(SerializationMacros, TestClassPtrHasMethodDeduction) {
  typedef ComplexEntry* T1;
  typedef SimpleEntry* T2;
  ASSERT_EQ(HasIsBinaryEqual<T1>::value, 1);
  ASSERT_EQ(HasIsBinaryEqual<T2>::value, 0);
}

TEST(SerializationMacros, TestClassHasStreamOperator) {
  ComplexEntry e1;
  e1.setRandom();

  streamIf<HasOStreamOperator<std::ostream, decltype(e1)>::value, decltype(e1) >::eval(e1);

  ASSERT_EQ((HasOStreamOperator<std::ostream, SimpleEntry>::value), 1);
  ASSERT_EQ((HasOStreamOperator<std::ostream, ComplexEntry>::value), 0);
}

TEST(SerializationMacros, TestSharedPtrHasStreamOperator) {
  typedef boost::shared_ptr<ComplexEntry> T1;
  typedef boost::shared_ptr<SimpleEntry> T2;

  T1 e1(new ComplexEntry);
  e1->setRandom();

  streamIf<HasOStreamOperator<std::ostream, T1>::value, T1 >::eval(e1);

  ASSERT_EQ((HasOStreamOperator<std::ostream, T2>::value), 1);
  ASSERT_EQ((HasOStreamOperator<std::ostream, T1>::value), 0);
}


TEST(SerializationMacros, TestPtrHasStreamOperator) {
  typedef ComplexEntry* T1;
  typedef SimpleEntry* T2;

  T1 e1 = new ComplexEntry;
  e1->setRandom();

  streamIf<HasOStreamOperator<std::ostream, T1>::value, T1 >::eval(e1);

  ASSERT_EQ((HasOStreamOperator<std::ostream, T2>::value), 1);
  ASSERT_EQ((HasOStreamOperator<std::ostream, T1>::value), 0);

  delete e1;
}
