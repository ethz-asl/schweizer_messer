#include <sm/value_store/VerboseValueStore.hpp>

namespace sm {
namespace value_store {

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

namespace internal {

template <typename Base>
ValueHandle<bool> VerboseValueStoreT<Base>::getBool(const std::string & path, boost::optional<bool> def) const {
  return logValue(__func__, path, vs_->getBool(path, def), def);
}
template <typename Base>
ValueHandle<int> VerboseValueStoreT<Base>::getInt(const std::string & path, boost::optional<int> def) const {
  return logValue(__func__, path, vs_->getInt(path, def), def);
}
template <typename Base>
ValueHandle<double> VerboseValueStoreT<Base>::getDouble(const std::string & path, boost::optional<double> def) const {
  return logValue(__func__, path, vs_->getDouble(path, def), def);
}
template <typename Base>
ValueHandle<std::string> VerboseValueStoreT<Base>::getString(const std::string & path, boost::optional<std::string> def) const {
  return logValue(__func__, path, vs_->getString(path, def), def);
}
template <typename Base>
bool VerboseValueStoreT<Base>::hasKey(const std::string& path) const {
  return logValue(__func__, path, vs_->hasKey(path));
}

template <typename Base>
KeyValueStorePair VerboseValueStoreT<Base>::getChild(const std::string & key) const {
  log_(std::string(__func__) + "(" + key + ")");
  auto log = log_;
  return KeyValueStorePair(key, std::make_shared<VerboseValueStore>(vs_->getChild(key), [log, key](const std::string &text){ log("child(" + key + "):" + text);}));
}

template <typename Base>
template <typename T, typename O>
T VerboseValueStoreT<Base>::logValue(
    const char* func, const std::string& path, T&& v, O o) const {
  std::string extra = "";
  if (!std::is_same<bool, O>::value && o) {
    if (!vs_->hasKey(path)) {
      extra = "DEFAULT:";
    }
  }
  log_(std::string(func) + "(\"" + path + "\")->" + extra + getValue(v));
  return std::move(v);
}

template <typename Base>
bool VerboseValueStoreT<Base>::isChildSupported() const {
  return vs_->isChildSupported();
}

template <typename Base>
std::vector<KeyValueStorePair> VerboseValueStoreT<Base>::getChildren() const {
  log_(std::string(__func__) + "()");
  std::vector<KeyValueStorePair> verboseChildren;
  for (const auto& c : vs_->getChildren()){
    verboseChildren.push_back(this->getChild(c.getKey()));
  }
  return verboseChildren;
}

template class VerboseValueStoreT<ValueStore>;
template class VerboseValueStoreT<ExtendibleValueStore>;

} // namespace internal

template <typename T>
T VerboseExtendibleValueStore::logAddValue(
    const char* func, const std::string& path, T&& v) const {
  log_(std::string(func) + "(\"" + path + "\")->INITIAL:" + getValue(v));
  return std::move(v);
}

ValueHandle<bool> VerboseExtendibleValueStore::addBool(const std::string & path, bool initialValue) {
  return logAddValue(__func__, path, vs_->addBool(path, initialValue));
}
ValueHandle<int> VerboseExtendibleValueStore::addInt(const std::string & path, int initialValue) {
  return logAddValue(__func__, path, vs_->addInt(path, initialValue));
}
ValueHandle<double> VerboseExtendibleValueStore::addDouble(const std::string & path, double initialValue) {
  return logAddValue(__func__, path, vs_->addDouble(path, initialValue));
}
ValueHandle<std::string> VerboseExtendibleValueStore::addString(const std::string & path, std::string initialValue) {
  return logAddValue(__func__, path, vs_->addString(path, initialValue));
}

ExtendibleKeyValueStorePair VerboseExtendibleValueStore::getExtendibleChild(const std::string & key) const {
  log_(std::string(__func__) + "(" + key + ")");
  return ExtendibleKeyValueStorePair(key, std::make_shared<VerboseExtendibleValueStore>(vs_->getExtendibleChild(key), [log=log_, key](const std::string &text){ log("EC(" + key + "):" + text);}));
}
std::vector<ExtendibleKeyValueStorePair> VerboseExtendibleValueStore::getExtendibleChildren() const {
  log_(std::string(__func__) + "()");
  std::vector<ExtendibleKeyValueStorePair> verboseChildren;
  for (const auto& c : vs_->getExtendibleChildren()){
    verboseChildren.push_back(this->getExtendibleChild(c.getKey()));
  }
  return verboseChildren;
}

}
}
