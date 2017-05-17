#ifndef VALUE_STORE_LAYEREDVALUESTORE_HPP_
#define VALUE_STORE_LAYEREDVALUESTORE_HPP_

#include <utility>

#include "ValueStore.hpp"

namespace sm {
namespace value_store {

class LayeredValueStore : public ValueStore {
 public:
  template <typename ...ValueStores>
  LayeredValueStore(ValueStores && ... vss) {
    add(vss...);
  }
  template <typename ValueStoreA, typename ValueStoreB, typename ...ValueStores>
  void add(ValueStoreA && vsA, ValueStoreB && vsB, ValueStores && ... vss) {
    add(vsA);
    add(vsB, vss...);
  }
  void add(const std::shared_ptr<ValueStore> & p){ if(p) valuestores.push_back(p); }
  void add(ValueStoreRef & p){ if(p) valuestores.push_back(p.getValueStoreSharedPtr()); }

  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const;

  virtual bool hasKey(const std::string & path) const override;

  virtual bool isChildSupported() const override;
  virtual KeyValueStorePair getChild(const std::string & key) const override;
  virtual std::vector<KeyValueStorePair> getChildren() const override;
 private:
  void add(){}
  template <typename V, ValueHandle<V> (ValueStore::* Func)(const std::string &, boost::optional<V>) const>
  ValueHandle<V> getFromLayers(const std::string & path, boost::optional<V> def) const;

  std::vector<std::shared_ptr<ValueStore> > valuestores;
};

}
}


#endif /* VALUE_STORE_LAYEREDVALUESTORE_HPP_ */
