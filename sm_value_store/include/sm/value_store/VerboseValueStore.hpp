#ifndef VALUE_STORE_VERBOSEVALUESTORE_HPP_
#define VALUE_STORE_VERBOSEVALUESTORE_HPP_

#include <memory>
#include <functional>

#include "ValueStore.hpp"

namespace sm {
namespace value_store {

class VerboseValueStore : public ValueStore {
 public:
  VerboseValueStore(std::shared_ptr<ValueStore> vs, std::function<void(const std::string &)> log) : vs_(vs), log_(log) {}
  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const override;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const override;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const override;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const override;

  virtual bool hasKey(const std::string & path) const override;

  virtual bool isChildSupported() const override;
  virtual KeyValueStorePair getChild(const std::string & key) const override;
  virtual std::vector<KeyValueStorePair> getChildren() const override;
 private:
  std::shared_ptr<ValueStore> vs_;
  std::function<void(const std::string &)> log_;
};

}
}


#endif /* VALUE_STORE_VERBOSEVALUESTORE_HPP_ */
