#include <sm/value_store/ValueStore.hpp>
#include <sm/value_store/PrefixedValueStore.hpp>
#include <sm/value_store/LayeredValueStore.hpp>
#include <sm/value_store/PropertyTreeValueStore.hpp>

#include <unordered_map>

#include <sm/assert_macros.hpp>
#include <sm/BoostPropertyTree.hpp>

namespace sm {
namespace value_store {

ValueStoreRef ValueStoreRef::getChild(const std::string & key) const {
  if(_vs->isChildSupported()){
    return _vs->getChild(key);
  }
  else {
    return ValueStoreRef(std::make_shared<PrefixedValueStore>(_vs, key));
  }
}

ValueHandle<bool> PrefixedValueStore::getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const {
  return _vs->getBool(_prefix + path, def);
}
ValueHandle<int> PrefixedValueStore::getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const {
  return _vs->getInt(_prefix + path, def);
}
ValueHandle<double> PrefixedValueStore::getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const {
  return _vs->getDouble(_prefix + path, def);
}
ValueHandle<std::string> PrefixedValueStore::getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const {
  return _vs->getString(_prefix + path, def);
}
bool PrefixedValueStore::hasKey(const std::string& path) const {
  return _vs->hasKey(_prefix + path);
}

KeyValueStorePair PrefixedValueStore::getChild(const std::string & key) const {
  return KeyValueStorePair(key, std::make_shared<PrefixedValueStore>(_vs, _prefix + key));
}
std::vector<KeyValueStorePair> PrefixedValueStore::getChildren() const {
  SM_THROW(std::runtime_error, "Not implemented, yet");
}

ValueHandle<bool> LayeredValueStore::getBool(const std::string & path, boost::optional<bool> def) const {
 return getFromLayers<bool, &ValueStore::getBool>(path, def);
}
ValueHandle<int> LayeredValueStore::getInt(const std::string & path, boost::optional<int> def) const {
 return getFromLayers<int, &ValueStore::getInt>(path, def);
}
ValueHandle<double> LayeredValueStore::getDouble(const std::string & path, boost::optional<double> def) const {
 return getFromLayers<double, &ValueStore::getDouble>(path, def);
}
ValueHandle<std::string> LayeredValueStore::getString(const std::string & path, boost::optional<std::string> def) const {
 return getFromLayers<std::string, &ValueStore::getString>(path, def);
}
bool LayeredValueStore::hasKey(const std::string& path) const {
  for(auto & v: valuestores){
    if(! v) continue;
    if(v->hasKey(path)){
      return true;
    }
  }
  return false;
}

template <typename V, ValueHandle<V> (ValueStore::* Func)(const std::string &, boost::optional<V>) const>
ValueHandle<V> LayeredValueStore::getFromLayers(const std::string & path, boost::optional<V> def) const {
 int c = valuestores.size();
 for(auto & vs : valuestores) {
   if(--c){
     if(vs->hasKey(path))
       return ((&(*vs))->*Func)(path, boost::optional<V>());
   }
   else{
     return ((&(*vs))->*Func)(path, def);
   }
 }
 return V(); // dummy, will never happen
}

bool LayeredValueStore::isChildSupported() const {
  for(auto & v: valuestores){
    if(v && !v->isChildSupported()) return false;
  }
  return true;
}
KeyValueStorePair LayeredValueStore::getChild(const std::string & key) const {
  std::vector<KeyValueStorePair> childLayers;
  for(auto & v: valuestores){
    if(! v) continue;
    childLayers.emplace_back(v->getChild(key));
  }
  if(childLayers.size() == 1){
    return childLayers.front();
  }
  else {
    auto layeredVS = std::make_shared<LayeredValueStore>();
    for(auto vsp : childLayers){
      layeredVS->add(vsp.getValueStoreSharedPtr());
    }
    return KeyValueStorePair(key, layeredVS);
  }
}

std::vector<KeyValueStorePair> LayeredValueStore::getChildren() const {
  std::unordered_map<std::string, std::vector<KeyValueStorePair> > map;
  for(auto & v: valuestores){
    if(! v) continue;
    for(auto & c: v->getChildren()){
      map[c.getKey()].push_back(c);
    }
  }

  std::vector<KeyValueStorePair> ret;
  for(auto & p : map){
    if(p.second.size() == 1){
      ret.push_back(KeyValueStorePair(p.first, p.second.front().getValueStoreSharedPtr()));
    }
    else {
      auto layeredVS = std::make_shared<LayeredValueStore>();
      for(auto & vsp : p.second){
        layeredVS->add(vsp.getValueStoreSharedPtr());
      }
      ret.push_back(KeyValueStorePair(p.first, layeredVS));
    }
  }
  return ret;
}

ValueStoreRef::ValueStoreRef(sm::PropertyTree bpt) : _vs(std::make_shared<PropertyTreeValueStore>(bpt)) {
}

ValueStoreRef::ValueStoreRef() : ValueStoreRef(sm::BoostPropertyTree()){
}

ValueStoreRef::ValueStoreRef(ValueStore::SharedPtr spVs) : _vs(spVs) {
  if(!spVs){
    throw std::runtime_error("ValueStoreRef was given a null pointer!");
  }
}

ExtendibleValueStoreRef::ExtendibleValueStoreRef(sm::PropertyTree bpt) : ValueStoreRef(bpt) {
  _evs = std::static_pointer_cast<PropertyTreeValueStore>(_vs);
}

}
}
