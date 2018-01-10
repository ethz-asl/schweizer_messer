#include <sm/value_store/PrefixedValueStore.hpp>

#include <unordered_map>
#include <string>

#include <sm/assert_macros.hpp>

namespace sm {
namespace value_store {

ValueHandle<bool> PrefixedValueStore::getBool(const std::string & path, boost::optional<bool> def) const {
  return vs_->getBool(applyPrefix(path), def);
}
ValueHandle<int> PrefixedValueStore::getInt(const std::string & path, boost::optional<int> def) const {
  return vs_->getInt(applyPrefix(path), def);
}
ValueHandle<double> PrefixedValueStore::getDouble(const std::string & path, boost::optional<double> def) const {
  return vs_->getDouble(applyPrefix(path), def);
}
ValueHandle<std::string> PrefixedValueStore::getString(const std::string & path, boost::optional<std::string> def) const {
  return vs_->getString(applyPrefix(path), def);
}
bool PrefixedValueStore::hasKey(const std::string& path) const {
  bool isPossible;
  auto && prefixedPath = applyPrefix(path, &isPossible);
  return isPossible && vs_->hasKey(prefixedPath);
}

KeyValueStorePair PrefixedValueStore::getChild(const std::string & key) const {
  bool isPossible;
  auto && prefixedKey = applyPrefix(key, &isPossible);
  if(isPossible){
    if(PrefixMode::REMOVE == mode_ && (prefixedKey.empty() || prefixedKey == "/")){
      return KeyValueStorePair(key, vs_);
    }
    return KeyValueStorePair(key, std::make_shared<PrefixedValueStore>(vs_, mode_, prefixedKey));
  } else {
    return KeyValueStorePair(key, ValueStoreRef());
  }
}
std::vector<KeyValueStorePair> PrefixedValueStore::getChildren() const {
  SM_THROW(std::runtime_error, "Not implemented, yet");
}

std::string PrefixedValueStore::applyPrefix(const std::string& path, bool* isPossiblePtr) const {
  switch(mode_){
    case PrefixMode::ADD:
      return prefix_ + path;
    case PrefixMode::REMOVE:
      if (path.size() >= prefix_.size() && path.substr(0, prefix_.size()) == prefix_) {
        if(isPossiblePtr) {
          *isPossiblePtr = true;
        }
        return path.substr(prefix_.size());
      } else {
        if(isPossiblePtr) {
          *isPossiblePtr = path.size() == prefix_.size() - 1 && path + "/" == prefix_;
          return std::string();
        } else {
          SM_THROW(std::runtime_error, "path does not contain the prefix (" << prefix_ << "): " << path);
        }
      }
    default:
      SM_THROW(std::runtime_error, "Unknown mode " << size_t(mode_));
  }
}

bool PrefixedValueStore::isChildSupported() const {
  switch(mode_){
    case PrefixMode::REMOVE:
      return vs_->isChildSupported();
    default:
      return true;
  }
}

}
}
