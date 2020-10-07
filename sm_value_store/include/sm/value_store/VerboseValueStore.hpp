#ifndef VALUE_STORE_VERBOSEVALUESTORE_HPP_
#define VALUE_STORE_VERBOSEVALUESTORE_HPP_

#include <memory>
#include <functional>

#include "ValueStore.hpp"

namespace sm {
namespace value_store {
namespace internal {
template <typename Base>
class VerboseValueStoreT : public Base {
 public:
  VerboseValueStoreT(std::shared_ptr<Base> vs, std::function<void(const std::string &)> log) : vs_(vs), log_(log) {}
  ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const override;
  ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const override;
  ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const override;
  ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const override;

  bool hasKey(const std::string & path) const override;

  bool isChildSupported() const override;
  KeyValueStorePair getChild(const std::string & key) const override;
  std::vector<KeyValueStorePair> getChildren() const override;

  std::shared_ptr<Base> getUnderlyingValueStore() const {
    return vs_;
  }
 protected:
  std::shared_ptr<Base> vs_;
  std::function<void(const std::string &)> log_;
 private:
  template <typename T, typename O = bool>
  T logValue(const char * func, const std::string & path, T && v, O o = false) const;
};

extern template class VerboseValueStoreT<ValueStore>;
extern template class VerboseValueStoreT<ExtendibleValueStore>;
}

using VerboseValueStore = internal::VerboseValueStoreT<ValueStore>;

class VerboseExtendibleValueStore : public internal::VerboseValueStoreT<ExtendibleValueStore> {
 public:
  using internal::VerboseValueStoreT<ExtendibleValueStore>::VerboseValueStoreT;
  ValueHandle<bool> addBool(const std::string & path, bool initialValue) override;
  ValueHandle<int> addInt(const std::string & path, int initialValue) override;
  ValueHandle<double> addDouble(const std::string & path, double initialValue) override;
  ValueHandle<std::string> addString(const std::string & path, std::string initialValue) override;

  ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const override;
  std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const override;

 private:
  template <typename T>
  T logAddValue(const char * func, const std::string & path, T && v) const;
};

}
}


#endif /* VALUE_STORE_VERBOSEVALUESTORE_HPP_ */
