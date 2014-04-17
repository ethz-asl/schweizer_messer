#ifndef HASH_ID_HPP_
#define HASH_ID_HPP_

#include <chrono>
#include <cstring>
#include <sstream>

namespace sm {

/**
 * Randomly initialized 128 bit hash
 */
class HashId {
 public:
  /**
   * Initializes to a random 128 bit string, seeding on the time in nanoseconds
   * of the first call to this function
   */
  HashId();

  const std::string hexString() const;

  bool operator <(const HashId& other) const;
  bool operator >(const HashId& other) const;
  bool operator ==(const HashId& other) const;

  void setInvalid();
  bool isValid();

 private:
  /**
   * Time seed from nanoseconds. Covers 584 years if we assume no two agents
   * initialize in the same nanosecond.
   */
  static int64_t time64();

  union HashVal{
    char c[16];
    uint_fast64_t u64[2];
  };
  HashVal val_;
};

} // namespace sm

#endif /* HASH_ID_HPP_ */
