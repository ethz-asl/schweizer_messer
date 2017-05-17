#include <sm/value_store/VerboseValueStore.hpp>

namespace sm {
namespace value_store {

ValueHandle<bool> VerboseValueStore::getBool(const std::string & path, boost::optional<bool> def) const {
  log_(std::string(__func__) + "(" + path + ")");
  return vs_->getBool(path, def);
}
ValueHandle<int> VerboseValueStore::getInt(const std::string & path, boost::optional<int> def) const {
  log_(std::string(__func__) + "(" + path + ")");
  return vs_->getInt(path, def);
}
ValueHandle<double> VerboseValueStore::getDouble(const std::string & path, boost::optional<double> def) const {
  log_(std::string(__func__) + "(" + path + ")");
  return vs_->getDouble(path, def);
}
ValueHandle<std::string> VerboseValueStore::getString(const std::string & path, boost::optional<std::string> def) const {
  log_(std::string(__func__) + "(" + path + ")");
  return vs_->getString(path, def);
}
bool VerboseValueStore::hasKey(const std::string& path) const {
  log_(std::string(__func__) + "(" + path + ")");
  return vs_->hasKey(path);
}

KeyValueStorePair VerboseValueStore::getChild(const std::string & key) const {
  log_(std::string(__func__) + "(" + key + ")");
  auto log = log_;
  return KeyValueStorePair(key, std::make_shared<VerboseValueStore>(vs_->getChild(key), [log, key](const std::string &text){ log("child(" + key + "):" + text);}));
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
