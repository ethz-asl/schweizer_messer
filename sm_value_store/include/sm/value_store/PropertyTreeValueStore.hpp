#ifndef VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_
#define VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_

#include "ValueStore.hpp"

#include <sm/PropertyTree.hpp>

namespace sm {
namespace value_store {

class PropertyTreeValueStore : public ExtendibleValueStore, public sm::PropertyTree {
 public:
  PropertyTreeValueStore(const sm::PropertyTree & pt) : sm::PropertyTree(pt) {}
  ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const override;
  ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const override;
  ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const override;
  ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const override;

  bool hasKey(const std::string& path) const override;

  KeyValueStorePair getChild(const std::string & key) const override;
  std::vector<KeyValueStorePair> getChildren() const override;

  ValueHandle<bool> addBool(const std::string & path, bool initialValue) override;
  ValueHandle<int> addInt(const std::string & path, int initialValue) override;
  ValueHandle<double> addDouble(const std::string & path, double initialValue) override;
  ValueHandle<std::string> addString(const std::string & path, std::string initialValue) override;

  ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const override;
  std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const override;

  bool isEmpty() const override;
 private:
  friend class ValueStoreRef;
  template <typename T> ValueHandle<T> getFromPt(const std::string & path, boost::optional<T> def) const;
};

}
}

#endif /* VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_ */
