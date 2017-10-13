#include <sm/value_store/VerboseValueStore.hpp>

namespace sm {
namespace value_store {

ValueHandle<bool> VerboseValueStore::getBool(const std::string & path, boost::optional<bool> def) const {
  return logValue(__func__, path, vs_->getBool(path, def), def);
}
ValueHandle<int> VerboseValueStore::getInt(const std::string & path, boost::optional<int> def) const {
  return logValue(__func__, path, vs_->getInt(path, def), def);
}
ValueHandle<double> VerboseValueStore::getDouble(const std::string & path, boost::optional<double> def) const {
  return logValue(__func__, path, vs_->getDouble(path, def), def);
}
ValueHandle<std::string> VerboseValueStore::getString(const std::string & path, boost::optional<std::string> def) const {
  return logValue(__func__, path, vs_->getString(path, def), def);
}
bool VerboseValueStore::hasKey(const std::string& path) const {
  return logValue(__func__, path, vs_->hasKey(path));
}

KeyValueStorePair VerboseValueStore::getChild(const std::string & key) const {
  log_(std::string(__func__) + "(" + key + ")");
  auto log = log_;
  return KeyValueStorePair(key, std::make_shared<VerboseValueStore>(vs_->getChild(key), [log, key](const std::string &text){ log("child(" + key + "):" + text);}));
}


template <typename T>
struct get_value {
  const T & operator () (const T & v) {
    return v;
  }
};

template <typename T>
struct get_value<ValueHandle<T>> {
  T operator () (const ValueHandle<T> & v) {
    return v.get();
  }
};

template <typename T>
std::string getValue(const T & v) {
  return std::to_string(get_value<T>()(v));
}

std::string getValue(const ValueHandle<std::string> & v) {
  return std::string("\"") + v.get() + '"';
}

template <typename T, typename O>
T VerboseValueStore::logValue(const char * func, const std::string & path, T && v, O o) const {
  std::string extra = "";
  if(!std::is_same<bool, O>::value && o){
    if(!vs_->hasKey(path)){
      extra = "DEFAULT:";
    }
  }
  log_(std::string(func) + "(\"" + path + "\")->" + extra + getValue(v));
  return std::move(v);
}

bool VerboseValueStore::isChildSupported() const {
  return vs_->isChildSupported();
}

std::vector<KeyValueStorePair> VerboseValueStore::getChildren() const {
  log_(std::string(__func__) + "()");
  return vs_->getChildren(); //TODO instrument with VerboseValueStore, too.
}

}
}
