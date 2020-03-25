#include <sm/value_store/ValueStore.hpp>

#include <unordered_map>
#include <boost/make_shared.hpp>

#include <sm/assert_macros.hpp>
#include <sm/value_store/PropertyTreeValueStore.hpp>
#include <sm/PropertyTreeImplementation.hpp>
#include <sm/BoostPropertyTreeImplementation.hpp>
#include <sm/BoostPropertyTree.hpp>

namespace sm {
namespace value_store {

template <typename Class, typename T>
struct PropertyTreeAccessorMap;

template <typename Class>
struct PropertyTreeAccessorMap<Class, bool> {
  static constexpr void (Class ::*setter) (const std::string & path, bool) = &Class::setBool;
  static constexpr bool (Class ::*getter) (const std::string & path) const = &Class::getBool;
  static constexpr bool (Class ::*getterD) (const std::string & path, bool) const = &Class::getBool;
};
template <typename Class>
struct PropertyTreeAccessorMap<Class, int> {
  static constexpr void (Class ::*setter) (const std::string & path, int) = &Class::setInt;
  static constexpr int (Class ::*getter) (const std::string & path) const = &Class::getInt;
  static constexpr int (Class ::*getterD) (const std::string & path, int) const = &Class::getInt;
};
template <typename Class>
struct PropertyTreeAccessorMap<Class, double> {
  static constexpr void (Class ::*setter) (const std::string & path, double) = &Class::setDouble;
  static constexpr double (Class ::*getter) (const std::string & path) const = &Class::getDouble;
  static constexpr double (Class ::*getterD) (const std::string & path, double) const = &Class::getDouble;
};
template <typename Class>
struct PropertyTreeAccessorMap<Class, std::string> {
  static constexpr void (Class ::*setter) (const std::string & path, const std::string &) = &Class::setString;
  static constexpr std::string (Class ::*getter) (const std::string & path) const = &Class::getString;
  static constexpr std::string (Class ::*getterD) (const std::string & path, const std::string &) const = &Class::getString;
};

template <typename T>
class PropertyTreeValueStoreValueHanlder : public ValueHandleImpl<T> {
 public:
  PropertyTreeValueStoreValueHanlder(std::string path, const PropertyTree & pt, T /*defaultValue*/) : path(path), pt(const_cast<PropertyTree&>(pt)) {
  }

  bool isUpdateable() const override { return true; }
  void update (T newValue) override {
    (pt.*PropertyTreeAccessorMap<PropertyTree, T>::setter)(path, newValue);
  }
  T get() const override { return (pt.*PropertyTreeAccessorMap<const PropertyTree, T>::getter)(path); }
  ~PropertyTreeValueStoreValueHanlder() override{}
 private:
  T value;
  std::string path;
  PropertyTree pt;
};

template <typename T> ValueHandle<T> PropertyTreeValueStore::getFromPt(const std::string & path, boost::optional<T> def) const {
  if(def){
    return (const_cast<PropertyTreeValueStore*>(this)->* PropertyTreeAccessorMap<sm::PropertyTree, T>::getterD)(path, *def);
  }
  else{
    return ValueHandle<T>(new PropertyTreeValueStoreValueHanlder<T>(path, *this, (this->* PropertyTreeAccessorMap<const sm::PropertyTree, T>::getter)(path)));
  }
}

ValueHandle<bool> PropertyTreeValueStore::getBool(const std::string & path, boost::optional<bool> def) const {
  return getFromPt(path, def);
}

ValueHandle<int> PropertyTreeValueStore::getInt(const std::string & path, boost::optional<int> def) const {
  return getFromPt(path, def);
}
ValueHandle<double> PropertyTreeValueStore::getDouble(const std::string & path, boost::optional<double> def) const {
  return getFromPt(path, def);
}
ValueHandle<std::string> PropertyTreeValueStore::getString(const std::string & path, boost::optional<std::string> def) const {
  return getFromPt(path, def);
}

bool PropertyTreeValueStore::hasKey(const std::string& path) const {
  return ConstPropertyTree::doesKeyExist(path);
}

std::vector<KeyValueStorePair> PropertyTreeValueStore::getChildren() const {
  auto children = PropertyTree::getChildren();
  std::vector<KeyValueStorePair> ret;
  ret.reserve(children.size());
  for(auto & c : children){
    ret.emplace_back(c.key, std::make_shared<PropertyTreeValueStore>(c.pt));
  }
  return ret;
}

KeyValueStorePair PropertyTreeValueStore::getChild(const std::string & key) const {
  return KeyValueStorePair(key, std::make_shared<PropertyTreeValueStore>(PropertyTree::getChild(key)));
}

ValueHandle<bool> PropertyTreeValueStore::addBool(const std::string& path, bool initialValue) {
  PropertyTree::setBool(path, initialValue);
  return initialValue;
}

ValueHandle<int> PropertyTreeValueStore::addInt(const std::string& path, int initialValue) {
  PropertyTree::setInt(path, initialValue);
  return initialValue;
}

ValueHandle<double> PropertyTreeValueStore::addDouble(const std::string& path, double initialValue) {
  PropertyTree::setDouble(path, initialValue);
  return initialValue;
}

ValueHandle<std::string> PropertyTreeValueStore::addString(const std::string& path, std::string initialValue) {
  PropertyTree::setString(path, initialValue);
  return initialValue;
}

ExtendibleKeyValueStorePair PropertyTreeValueStore::getExtendibleChild(const std::string& key ) const {
  return ExtendibleKeyValueStorePair(key, std::make_shared<PropertyTreeValueStore>(PropertyTree::getChild(key)));
}

std::vector<ExtendibleKeyValueStorePair> PropertyTreeValueStore::getExtendibleChildren() const {
  auto children = PropertyTree::getChildren();
  std::vector<ExtendibleKeyValueStorePair> ret;
  ret.reserve(children.size());
  for(auto & c : children){
    ret.emplace_back(c.key, std::make_shared<PropertyTreeValueStore>(c.pt));
  }
  return ret;
}

class ValueStorePropertyTreeImpl : public sm::PropertyTreeImplementation {
 public:
  ValueStorePropertyTreeImpl(const ValueStoreRef vs) : vs_(vs) {}
  ~ValueStorePropertyTreeImpl() override{}

  double getDouble(const std::string & key) const override {
    return vs_.getDouble(translateKey(key));
  }
  double getDouble(const std::string & key, double defaultValue) const override {
    return vs_.getDouble(translateKey(key), defaultValue);
  }
  double getDouble(const std::string & /* key */, double /* defaultValue */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }

  int getInt(const std::string & key) const override {
    return vs_.getInt(translateKey(key));
  }
  int getInt(const std::string & key, int defaultValue) const override {
    return vs_.getInt(translateKey(key), defaultValue);
  }
  int getInt(const std::string & /* key */, int /* defaultValue */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }

  bool getBool(const std::string & key) const override {
    return vs_.getBool(translateKey(key));
  }
  bool getBool(const std::string & key, bool defaultValue) const override {
    return vs_.getBool(translateKey(key), defaultValue);
  }
  bool getBool(const std::string & /* key */, bool /* defaultValue */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }

  std::string getString(const std::string & key) const override {
    return vs_.getString(translateKey(key));
  }
  std::string getString(const std::string & key, const std::string & defaultValue) const override {
    return vs_.getString(translateKey(key), defaultValue);
  }
  std::string getString(const std::string & /* key */, const std::string & /* defaultValue */)  override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }

  void setDouble(const std::string & /* key */, double /* value */) override{
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }
  void setInt(const std::string & /* key */, int /* value */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }
  void setBool(const std::string & /* key */, bool /* value */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }
  void setString(const std::string & /* key */, const std::string & /* value */) override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }

  bool doesKeyExist(const std::string & key) const override {
    return vs_.hasKey(translateKey(key));
  }

  std::vector<KeyPropertyTreePair> getChildren(const std::string & /* key */) const override {
    SM_THROW(std::runtime_error, "Not implemented, yet");
  }
 private:
  const ValueStoreRef vs_;

  std::string translateKey(const std::string & key) const {
    if(!key.empty() && key.at(0) == '/'){
      return key.substr(1);
    }
    else {
      return key;
    }
  }
};

sm::ConstPropertyTree ValueStoreRef::asPropertyTree() const {
  return ConstPropertyTree(boost::make_shared<ValueStorePropertyTreeImpl>(*this));
}

sm::ValueStoreRef ValueStoreRef::fromString(const std::string & content){
  sm::BoostPropertyTree pt;
  pt.loadString(content);
  return pt;
}

sm::ValueStoreRef ValueStoreRef::fromFile(const std::string & path){
  sm::BoostPropertyTree bpt;
  bpt.load(path);
  return bpt;
}

sm::ExtendibleValueStoreRef ExtendibleValueStoreRef::fromString(const std::string & content){
  sm::BoostPropertyTree pt;
  pt.loadString(content);
  return pt;
}

sm::ExtendibleValueStoreRef ExtendibleValueStoreRef::fromFile(const std::string & path){
  sm::BoostPropertyTree bpt;
  bpt.load(path);
  return bpt;
}

bool PropertyTreeValueStore::isEmpty() const {
  if(auto ptr = dynamic_cast<sm::BoostPropertyTreeImplementation*>(_imp.get())) {
    return ptr->begin() == ptr->end();
  }
  return false;
}

sm::BoostPropertyTreeImplementation* ValueStoreRef::getBptPtr() const {
  sm::value_store::PropertyTreeValueStore* ptvs = dynamic_cast<PropertyTreeValueStore*>(_vs.get());
  if (ptvs) {
    return dynamic_cast<BoostPropertyTreeImplementation*>(ptvs->_imp.get());
  } else {
    return nullptr;
  }
}

bool ValueStoreRef::canSave() const {
  return getBptPtr() != nullptr;
}

void ValueStoreRef::saveTo(const std::string& path) const {
  auto bptPtr = getBptPtr();
  if(!bptPtr){
    SM_THROW(std::runtime_error, "Cannot save this value store. Check with canSave() first!");
  }
  boost::shared_ptr<BoostPropertyTreeImplementation> bptSharedPtr(bptPtr, [](sm::BoostPropertyTreeImplementation*) {});
  BoostPropertyTree(bptSharedPtr).save(path);
}

}
}
