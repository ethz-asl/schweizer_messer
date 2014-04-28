#ifndef HASH_ID_HPP_
#define HASH_ID_HPP_

#include <chrono>
#include <cstring>
#include <iomanip>
#include <sstream>

namespace sm {

/**
 * Randomly initialized 128 bit hash
 * TODO(tcies) (de)serialization
 */
class HashId {
 public:
  /**
   * Initializes to a random 128 bit string, seeding on the time in nanoseconds
   * of the first call to this function
   */
  inline HashId(){
    static std::mt19937_64 rng(time64());
    val_.u64[0] = rng();
    val_.u64[1] = rng();
  }

  /**
   * Returns hexadecimal string for debugging or serialization
   */
  inline const std::string hexString() const{
    std::ostringstream ss;
    for (size_t i = 0; i < sizeof(val_); ++i){
      ss << std::hex << std::setfill('0') << std::setw(2) <<
          static_cast<int>(val_.c[i]);
    }
    return ss.str();
  }

  /**
   * Deserialize from hexadecimal string. Serialization and Deserialization
   * could be made more performant by using blobs.
   */
  inline bool fromHexString(const std::string& hexString){
    // hexadecimal string takes 2 characters per byte
    if (hexString.size() != 2*sizeof(val_)){
      return false;
    }
    for (size_t i = 0; i < sizeof(val_); ++i){
      unsigned int integerValue;
      std::istringstream ss(std::string(hexString, 2*i, 2));
      ss >> std::hex >> integerValue;
      val_.c[i] = static_cast<unsigned char>(integerValue);
    }
    return true;
  }

  inline bool operator <(const HashId& other) const{
    if (val_.u64[0] == other.val_.u64[0]){
      return val_.u64[1] < other.val_.u64[1];
    }
    return val_.u64[0] < other.val_.u64[0];
  }
  inline bool operator >(const HashId& other) const{
    if (val_.u64[0] == other.val_.u64[0]){
      return val_.u64[1] > other.val_.u64[1];
    }
    return val_.u64[0] > other.val_.u64[0];
  }
  inline bool operator ==(const HashId& other) const{
    return val_.u64[0] == other.val_.u64[0] && val_.u64[1] == other.val_.u64[1];
  }
  inline bool operator !=(const HashId& other) const{
    return !(*this == other);
  }

  /**
   * Invalidation mechanism
   */
  inline void setInvalid(){
    memset(&val_, 0, sizeof(val_));
  }
  inline bool isValid() const{
    return val_.u64[0] != 0 || val_.u64[1] != 0;
  }

 private:
  /**
   * Time seed from nanoseconds. Covers 584 years if we assume no two agents
   * initialize in the same nanosecond.
   */
  inline static int64_t time64(){
    std::chrono::system_clock::duration current =
        std::chrono::high_resolution_clock::now().time_since_epoch();
    using std::chrono::duration_cast;
    using std::chrono::nanoseconds;
    // count() specified to return at least 64 bits
    return duration_cast<nanoseconds>(current).count();
  }

  /**
   * Internal representation
   */
  union HashVal{
    unsigned char c[16];
    uint_fast64_t u64[2];
  };
  HashVal val_;
};

} // namespace sm

#endif /* HASH_ID_HPP_ */
