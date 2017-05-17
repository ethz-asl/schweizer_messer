#ifndef VALUE_STORE_PREFIXEDVALUESTORE_HPP_
#define VALUE_STORE_PREFIXEDVALUESTORE_HPP_


#include "ValueStore.hpp"

namespace sm {
namespace value_store {

class PrefixedValueStore : public ValueStore {
 public:
  enum class PrefixMode {
    ADD, REMOVE
  };
  PrefixedValueStore(ValueStore::SharedPtr vs, PrefixMode mode, const std::string & prefix) : vs_(vs), prefix_(prefix + "/"), mode_(mode) {}
  PrefixedValueStore(const ValueStoreRef & vs, PrefixMode mode, const std::string & prefix) : PrefixedValueStore(vs.getValueStoreSharedPtr(), mode, prefix){}

  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def) const override;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def) const override;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def) const override;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def) const override;

  virtual bool hasKey(const std::string & path) const override;

  virtual KeyValueStorePair getChild(const std::string & key) const override;
  virtual std::vector<KeyValueStorePair> getChildren() const override;
  virtual bool isChildSupported() const override;
 private:
  std::string applyPrefix(const std::string & path, bool* isPossiblePtr = nullptr) const;
  ValueStore::SharedPtr vs_;
  std::string prefix_;
  const PrefixMode mode_;
};

}
}


#endif /* VALUE_STORE_PREFIXEDVALUESTORE_HPP_ */
