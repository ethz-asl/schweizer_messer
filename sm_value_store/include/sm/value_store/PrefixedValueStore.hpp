#ifndef VALUE_STORE_PREFIXEDVALUESTORE_HPP_
#define VALUE_STORE_PREFIXEDVALUESTORE_HPP_


#include "ValueStore.hpp"

namespace sm {
namespace value_store {

class PrefixedValueStore : public ValueStore {
 public:
  PrefixedValueStore(ValueStore::SharedPtr vs, const std::string & prefix) : _vs(vs), _prefix(prefix + "/") {}
  PrefixedValueStore(ValueStore & vs, const std::string & prefix) : _vs(std::shared_ptr<ValueStore>(&vs, [](ValueStore *){})), _prefix(prefix + "/") {}

  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def) const override;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def) const override;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def) const override;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def) const override;

  virtual bool hasKey(const std::string & path) const override;

  virtual KeyValueStorePair getChild(const std::string & key) const override;
  virtual std::vector<KeyValueStorePair> getChildren() const override;
 private:
  ValueStore::SharedPtr _vs;
  std::string _prefix;
};

}
}


#endif /* VALUE_STORE_PREFIXEDVALUESTORE_HPP_ */
