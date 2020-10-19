#include <sm/value_store/ValueStore.hpp>
#include <sm/value_store/PrefixedValueStore.hpp>
#include <sm/value_store/LayeredValueStore.hpp>
#include <sm/value_store/PropertyTreeValueStore.hpp>

#include <unordered_map>

#include <sm/assert_macros.hpp>
#include <sm/BoostPropertyTree.hpp>

namespace sm {
namespace value_store {


bool ValueStore::isEmpty() const {
  return false;
}

ValueStoreRef ValueStoreRef::getChild(const std::string & key) const {
  if(_vs->isChildSupported()){
    return _vs->getChild(key);
  }
  else {
    return ValueStoreRef(std::make_shared<PrefixedValueStore>(_vs, PrefixedValueStore::PrefixMode::ADD, key));
  }
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

std::string ValueStoreRef::findPathAndAlert(const std::vector<std::string> & pathsAndDeprecationWarnings, PathAlertHandler alertHandler) const {
  for(size_t i = 0; i < pathsAndDeprecationWarnings.size(); i++){
    const std::string & p = pathsAndDeprecationWarnings[i];
    if(!p.empty() && p[0] == '!') {
      std::string pp = p.substr(1);
      if (hasKey(pp)) {
        i++; // skip deprecation message in the input
        std::string message = i < pathsAndDeprecationWarnings.size() ?
            pathsAndDeprecationWarnings[i] :
            "Property name '" + pp + "' is deprecated! Use "
              + pathsAndDeprecationWarnings[0] + " instead.";
        if (alertHandler) {
          alertHandler(pp, message);
        } else {
          std::cerr << message << std::endl;
        }
        return pp;
      }
    } else if (hasKey(p)) {
      return p;
    }
  }
  return pathsAndDeprecationWarnings.front();
}

ExtendibleValueStoreRef::ExtendibleValueStoreRef() : ExtendibleValueStoreRef(sm::BoostPropertyTree()) {};

ExtendibleValueStoreRef::ExtendibleValueStoreRef(sm::PropertyTree bpt) : ExtendibleValueStoreRef(std::make_shared<PropertyTreeValueStore>(bpt)) {}

}
}

