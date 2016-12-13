#ifndef VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_
#define VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_

#include "ValueStore.hpp"

#include <sm/PropertyTree.hpp>

namespace sm {
namespace value_store {

class PropertyTreeValueStore : public ExtendibleValueStore, public sm::PropertyTree {
 public:
  PropertyTreeValueStore(const sm::PropertyTree & pt) : sm::PropertyTree(pt) {}
  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const override;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const override;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const override;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const override;

  virtual bool hasKey(const std::string& path) const override;

  virtual KeyValueStorePair getChild(const std::string & key) const override;
  virtual std::vector<KeyValueStorePair> getChildren() const override;

  virtual ValueHandle<bool> addBool(const std::string & path, bool initialValue) override;
  virtual ValueHandle<int> addInt(const std::string & path, int initialValue) override;
  virtual ValueHandle<double> addDouble(const std::string & path, double initialValue) override;
  virtual ValueHandle<std::string> addString(const std::string & path, std::string initialValue) override;

  virtual ExtendibleKeyValueStorePair addChild(const std::string & key) override;
  virtual ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const override;
  virtual std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const override;
 private:
  template <typename T> ValueHandle<T> getFromPt(const std::string & path, boost::optional<T> def) const;
};

}
}

#endif /* VALUE_STORE_PROPERTYTREEVALUESTORE_HPP_ */
