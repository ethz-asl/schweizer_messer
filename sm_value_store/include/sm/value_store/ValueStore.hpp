#ifndef VALUE_STORE_VALUESTORE_HPP_
#define VALUE_STORE_VALUESTORE_HPP_

#include <cassert>
#include <memory>
#include <string>
#include <vector>

#include <boost/optional.hpp>

namespace sm {
class ConstPropertyTree;
class PropertyTree;
class BoostPropertyTreeImplementation;

namespace value_store {

template <typename T>
class ValueHandleImpl {
 public:
  virtual bool isUpdateable() const { return false; }
  virtual void update(T newValue) = 0;
  virtual T get() const = 0;
  virtual ~ValueHandleImpl(){}
};

template <typename T>
class ConstValueHandleImpl : public ValueHandleImpl<T> {
 public:
  ConstValueHandleImpl(T v) : v(v) {}
  bool isUpdateable() const override { return false; }
  void update(T /*newValue*/) override { assert(false); }
  T get() const override { return v; }
  ~ConstValueHandleImpl() override {}
 private:
  const T v;
};

template <typename T>
class ValueHandle {
 public:
  explicit ValueHandle(ValueHandleImpl<T> * pImpl) : impl(pImpl) { assert(pImpl); }
  ValueHandle(T v) : impl(new ConstValueHandleImpl<T>(v)){ }
  ValueHandle(ValueHandle && move) = default;
  ValueHandle() = default;
  ValueHandle & operator = (ValueHandle && move) = default;

  bool isUpdateable() const { return impl->isUpdateable(); }
  void update(T newValue) { impl->update(newValue); }
  T get() const { return impl->get(); }
  inline operator T () const { return get(); }

  bool empty() const { return !impl; }

  ValueHandleImpl<T> & getImplementation() { return *impl; }
 private:
  std::unique_ptr<ValueHandleImpl<T> > impl;
};


class KeyValueStorePair;
class ValueStore {
 public:
  typedef std::shared_ptr<ValueStore> SharedPtr;
  //TODO (HannesSommer) Fix constness (probably requires ConstValueStore as for PropertyTree)
  virtual ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const = 0;
  virtual ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const = 0;
  virtual ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const = 0;
  virtual ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const = 0;

  virtual bool hasKey(const std::string & path) const = 0;

  virtual KeyValueStorePair getChild(const std::string & key) const = 0;

  virtual std::vector<KeyValueStorePair> getChildren() const = 0;

  virtual bool isChildSupported() const { return true ; }

  /**
   * Return whether the value store is empty.
   * Default implementation is always false
   * @return true if the value store is empty. But false is also allowed for non empty value stores.
   */
  virtual bool isEmpty() const;

  virtual bool isExtendible() const {
    return false;
  }

  virtual ~ValueStore(){}
};

namespace internal {
template <typename Class, typename T>
struct AccessorMap;

template <typename Class>
struct AccessorMap<Class, bool> {
  static constexpr ValueHandle<bool> (Class ::*getter) (const std::string & path, boost::optional<bool>) const = &Class::getBool;
};
template <typename Class>
struct AccessorMap<Class, int> {
  static constexpr ValueHandle<int> (Class ::*getter) (const std::string & path, boost::optional<int>) const = &Class::getInt;
};
template <typename Class>
struct AccessorMap<Class, double> {
  static constexpr ValueHandle<double> (Class ::*getter) (const std::string & path, boost::optional<double>) const = &Class::getDouble;
};
template <typename Class>
struct AccessorMap<Class, std::string> {
  static constexpr ValueHandle<std::string> (Class ::*getter) (const std::string & path, boost::optional<std::string>) const = &Class::getString;
};
}

class ExtendibleValueStoreRef;
class ValueStoreRef {
 public:
  /// brief create a value store reference pointing to a fresh empty value store (based on @see sm::BoostPropertyTree)
  ValueStoreRef();
  ValueStoreRef(ValueStore::SharedPtr spVs);
  explicit ValueStoreRef(ValueStore * vsPtr) : _vs(ValueStore::SharedPtr(vsPtr)) {}
  explicit ValueStoreRef(ValueStore & vs) : _vs(ValueStore::SharedPtr(&vs, [](ValueStore*){})) {}
  ValueStoreRef(sm::PropertyTree bpt);

  ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const {
    return _vs->getBool(path, def);
  }
  ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const {
    return _vs->getInt(path, def);
  }
  ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const {
    return _vs->getDouble(path, def);
  }
  ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const {
    return _vs->getString(path, def);
  }

  template <typename T>
  ValueHandle<T> get(const std::string & path, boost::optional<T> def = boost::optional<T>()) const {
    return (this->*internal::AccessorMap<ValueStoreRef, T>::getter)(path, def);
  }

  typedef std::function<void(std::string path, std::string arg)> PathAlertHandler;

  /**
  Like get(path, def) but with multiple path alternatives in \pathsWithAlerts.

  It also supports calling back the \alertHandler in case a path prefixed with
  an '!' is used.

  @param pathsWithAlerts[in] contains the path alternatives possibly prefixed
  with an '!' to indicate that the alertHandler should be called. In that case
  the next entry of the vector is considered a special argument to the
  \alertHandler and _not_ a path candidate.
  */
  template<typename T>
  ValueHandle<T> get(const std::vector<std::string> & pathsWithAlerts, boost::optional<T> def = boost::optional<T>(), PathAlertHandler alertHandler = PathAlertHandler()) const {
    return get<T>(findPathAndAlert(pathsWithAlerts, alertHandler), def);
  }

  bool isEmpty() const {
    return _vs->isEmpty();
  }

  bool hasKey(const std::string & path) const {
    return _vs->hasKey(path);
  }

  ValueStore & getValueStore() const { return *_vs; }

  ValueStoreRef getChild(const std::string & key) const;

  sm::ConstPropertyTree asPropertyTree() const;

  std::vector<KeyValueStorePair> getChildren() const { return _vs->getChildren(); }

  std::shared_ptr<ValueStore> getValueStoreSharedPtr() const { return _vs; }

  operator std::shared_ptr<ValueStore> () const { return getValueStoreSharedPtr(); }
  operator ValueStore & () const { return *getValueStoreSharedPtr(); }
  operator bool () const { return bool(_vs); }

  /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from string using @see sm::BoostPropertyTree::loadString .
  static ValueStoreRef fromString(const std::string & contentString);

  /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
  static ValueStoreRef fromFile(const std::string & path);

  /**
   * Return whether saveTo() may be used.
   * @return true iff saveTo can work (see there).
   */
  bool canSave() const;

  /**
   * Save to file. Currently, this only works for ValuesSoresRefs directly referring to sm::BoostPropertyTree objects (@see sm::BoostPropertyTree::save).
   * If in doubt, use canSave() to check first.
   */
  void saveTo(const std::string & path) const;

  bool isExtendible() const;
  ExtendibleValueStoreRef asExtendible() const;
 private:
  sm::BoostPropertyTreeImplementation* getBptPtr() const;

  std::string findPathAndAlert(const std::vector<std::string> & pathsWithAlerts, PathAlertHandler alertHandler) const;

  std::shared_ptr<ValueStore> _vs;
  friend class ExtendibleValueStoreRef;
};

class ConstKeyValueStorePair : public ValueStoreRef {
 public:
  ConstKeyValueStorePair(const std::string& key, const std::shared_ptr<ValueStore> & vs) : ValueStoreRef(vs), _key(key){}

  const std::string& getKey() const { return _key; }
 private:
  std::string _key;
};

class KeyValueStorePair : public ValueStoreRef {
 public:
  KeyValueStorePair(const std::string& key, const std::shared_ptr<ValueStore> & vs) : ValueStoreRef(vs), _key(key){}
  KeyValueStorePair(const std::string& key, const ValueStoreRef & vs) : ValueStoreRef(vs), _key(key){}

  const std::string& getKey() const { return _key; }
 private:
  std::string _key;
};

class ExtendibleKeyValueStorePair;
class ExtendibleValueStore : public ValueStore {
 public:
  typedef std::shared_ptr<ExtendibleValueStore> SharedPtr;
  virtual ValueHandle<bool> addBool(const std::string & path, bool initialValue) = 0;
  virtual ValueHandle<int> addInt(const std::string & path, int initialValue) = 0;
  virtual ValueHandle<double> addDouble(const std::string & path, double initialValue) = 0;
  virtual ValueHandle<std::string> addString(const std::string & path, std::string initialValue) = 0;

  virtual ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const = 0;
  virtual std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const = 0;

  ~ExtendibleValueStore() override{}

  bool isExtendible() const override {
    return true;
  }
};


class ExtendibleValueStoreRef : public ValueStoreRef {
 public:
  ExtendibleValueStoreRef();
  ExtendibleValueStoreRef(ExtendibleValueStore::SharedPtr spVs) : ValueStoreRef(spVs), _evs(spVs) {}
  explicit ExtendibleValueStoreRef(ExtendibleValueStore * vsPtr) : ExtendibleValueStoreRef(ExtendibleValueStore::SharedPtr(vsPtr)) {}
  explicit ExtendibleValueStoreRef(ExtendibleValueStore & vs) : ExtendibleValueStoreRef(ExtendibleValueStore::SharedPtr(&vs, [](ExtendibleValueStore*){})) {}
  ExtendibleValueStoreRef(sm::PropertyTree bpt);
  

  ValueHandle<bool> addBool(const std::string & path, bool initialValue) const {
    return _evs->addBool(path, initialValue);
  }
  ValueHandle<int> addInt(const std::string & path, int initialValue) const {
    return _evs->addInt(path, initialValue);
  }
  ValueHandle<double> addDouble(const std::string & path, double initialValue) const {
    return _evs->addDouble(path, initialValue);
  }
  ValueHandle<std::string> addString(const std::string & path, std::string initialValue) const {
    return _evs->addString(path, initialValue);
  }

  ExtendibleValueStore & getValueStore() { return *_evs; }

  inline ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const;
  std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const { return _evs->getExtendibleChildren(); }

  ExtendibleValueStore::SharedPtr getValueStoreSharedPtr() const { return _evs; }
  operator ExtendibleValueStore::SharedPtr () const { return getValueStoreSharedPtr(); }

  operator ExtendibleValueStore & () const { return *getValueStoreSharedPtr(); }

  /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from string using @see sm::BoostPropertyTree::loadString .
  static ExtendibleValueStoreRef fromString(const std::string & contentString);

  /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
  static ExtendibleValueStoreRef fromFile(const std::string & path);

 private:
  ExtendibleValueStore::SharedPtr  _evs;
};

class ExtendibleKeyValueStorePair : public ExtendibleValueStoreRef {
 public:
  ExtendibleKeyValueStorePair(const std::string& key, const std::shared_ptr<ExtendibleValueStore> & vs) : ExtendibleValueStoreRef(vs), _key(key){}

  const std::string& getKey() const { return _key; }
 private:
  std::string _key;
};

ExtendibleKeyValueStorePair ExtendibleValueStoreRef::getExtendibleChild(const std::string & key) const { return _evs->getExtendibleChild(key); }

}
using namespace value_store;

}


#endif /* VALUE_STORE_VALUESTORE_HPP_ */
