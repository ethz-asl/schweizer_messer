#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>
#include <boost/python/enum.hpp>

#include <sm/PropertyTree.hpp>
#include <sm/value_store/ValueStore.hpp>
#include <sm/value_store/LayeredValueStore.hpp>
#include <sm/value_store/PrefixedValueStore.hpp>
#include <functional>

void exportValueStoreRef()
{
  using namespace boost::python;
  using namespace sm::value_store;

  using ChildrenT = std::vector<KeyValueStorePair>;

  class_<ChildrenT>("ChildVector")
    .def(boost::python::vector_indexing_suite<ChildrenT>())
    .def("__iter__", boost::python::iterator<ChildrenT>())
  ;
  
  /// brief create a value store reference pointing to a fresh empty value store (based on @see sm::BoostPropertyTree)
  class_<ValueStoreRef>("ValueStoreRef", init<>())
    .def(init<ValueStoreRef>())
    .def(init<ValueStore::SharedPtr>())
    .def(init<sm::PropertyTree>())
    /// ValueStoreRef getChild(const std::string & key)
    .def("getChild", &ValueStoreRef::getChild)
    /// virtual std::vector<KeyValueStorePair> getChildren() const
    .def("getChildren", &ValueStoreRef::getChildren)
    /// sm::ConstPropertyTree asPropertyTree() const
    .def("asPropertyTree", &ValueStoreRef::asPropertyTree)
    /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
    /// static ValueStoreRef fromFile(const std::string & path)
    .def("fromFile", &ValueStoreRef::fromFile).staticmethod("fromFile")
    /// brief Create a ValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
    /// static ValueStoreRef fromFile(const std::string & path)
    .def("fromString", &ValueStoreRef::fromString).staticmethod("fromString")
    /// ValueHandle<bool> getBool(const std::string & path, boost::optional<bool> def = boost::optional<bool>()) const;
    .def("getBool", +[](ValueStoreRef * vs, const std::string & path){return vs->getBool(path).get();})
    .def("getBool", +[](ValueStoreRef * vs, const std::string & path, bool defaultValue){return vs->getBool(path, defaultValue).get();})
    /// ValueHandle<int> getInt(const std::string & path, boost::optional<int> def = boost::optional<int>()) const;
    .def("getInt", +[](ValueStoreRef * vs, const std::string & path){return vs->getInt(path).get();})
    .def("getInt", +[](ValueStoreRef * vs, const std::string & path, int defaultValue){return vs->getInt(path, defaultValue).get();})
    /// ValueHandle<double> getDouble(const std::string & path, boost::optional<double> def = boost::optional<double>()) const;
    .def("getDouble", +[](ValueStoreRef * vs, const std::string & path){return vs->getDouble(path).get();})
    .def("getDouble", +[](ValueStoreRef * vs, const std::string & path, double defaultValue){return vs->getDouble(path, defaultValue).get();})
    /// ValueHandle<std::string> getString(const std::string & path, boost::optional<std::string> def = boost::optional<std::string>()) const;
    .def("getString", +[](ValueStoreRef * vs, const std::string & path){return vs->getString(path).get();})
    .def("getString", +[](ValueStoreRef * vs, const std::string & path, const std::string & defaultValue){return vs->getString(path, defaultValue).get();})
    /// ValueHandle<bool> getBool(const std::string & path).update(bool newVal) const;
    .def("setBool", +[](ValueStoreRef * vs, const std::string & path, bool newVal){vs->getBool(path).update(newVal);})
    /// ValueHandle<int> getInt(const std::string & path).update(int newVal) const;
    .def("setInt", +[](ValueStoreRef * vs, const std::string & path, int newVal){vs->getInt(path).update(newVal);})
    /// ValueHandle<double> getDouble(const std::string & path).update(double newVal) const;
    .def("setDouble", +[](ValueStoreRef * vs, const std::string & path, double newVal){vs->getDouble(path).update(newVal);})
    /// ValueHandle<std::string> getString(const std::string & path).update(std::string newVal) const;
    .def("setString", +[](ValueStoreRef * vs, const std::string & path, const std::string& newVal){vs->getString(path).update(newVal);})
    /// void saveTo(const std::string & path) const;
    .def("saveTo", &ValueStoreRef::saveTo)
    /// bool hasKey(const std::string& path) const;
    .def("hasKey", &ValueStoreRef::hasKey)
  ;
}

void exportKeyValueStorePair()
{
  using namespace boost::python;
  using namespace sm::value_store;

  class_<KeyValueStorePair, bases<ValueStoreRef>>("KeyValueStorePair", init<const std::string&, const ValueStoreRef&>())
    ///const std::string& getKey() const
    .def("getKey", &KeyValueStorePair::getKey, return_value_policy<copy_const_reference>())
  ;
}

void exportExtendibleValueStoreRef()
{
  using namespace boost::python;
  using namespace sm::value_store;

  using ChildrenT = std::vector<ExtendibleKeyValueStorePair>;

  class_<ChildrenT>("ExtendibleChildVector")
    .def(boost::python::vector_indexing_suite<ChildrenT>())
    .def("__iter__", boost::python::iterator<ChildrenT>())
  ;

  class_<ExtendibleValueStoreRef, bases<ValueStoreRef>>("ExtendibleValueStoreRef", init<>())
    .def(init<ExtendibleValueStoreRef>())
    .def(init<ExtendibleValueStore::SharedPtr>())
    .def(init<sm::PropertyTree>())

    //ValueHandle<bool> addBool(const std::string & path, bool initialValue) const
    .def("addBool", +[](ExtendibleValueStoreRef * vs, const std::string & path, bool value){return vs->addBool(path, value).get();})
    //ValueHandle<int> addInt(const std::string & path, int initialValue) const
    .def("addInt", +[](ExtendibleValueStoreRef * vs, const std::string & path, int value){return vs->addInt(path, value).get();})
    //ValueHandle<double> addDouble(const std::string & path, double initialValue) const
    .def("addDouble", +[](ExtendibleValueStoreRef * vs, const std::string & path, double value){return vs->addDouble(path, value).get();})
    //ValueHandle<std::string> addString(const std::string & path, std::string initialValue) const
    .def("addString", +[](ExtendibleValueStoreRef * vs, const std::string & path, const std::string& value){return vs->addString(path, value).get();})
    /// brief Create a ExtendibleValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
    /// static ExtendibleValueStoreRef fromFile(const std::string & path)
    .def("fromFile", &ExtendibleValueStoreRef::fromFile).staticmethod("fromFile")
    /// brief Create a ExtendibleValueStoreRef to a BoostPropertyTree loaded from file using @see sm::BoostPropertyTree::load .
    /// static ExtendibleValueStoreRef fromFile(const std::string & path)
    .def("fromString", &ExtendibleValueStoreRef::fromString).staticmethod("fromString")
    //inline ExtendibleKeyValueStorePair getExtendibleChild(const std::string & key) const
    .def("getExtendibleChild", &ExtendibleValueStoreRef::getExtendibleChild)
    //std::vector<ExtendibleKeyValueStorePair> getExtendibleChildren() const
    .def("getExtendibleChildren", &ExtendibleValueStoreRef::getExtendibleChildren)
  ;
}

void exportExtendibleKeyValueStorePair()
{
  using namespace boost::python;
  using namespace sm::value_store;

  class_<ExtendibleKeyValueStorePair, bases<ExtendibleValueStoreRef>>("ExtendibleKeyValueStorePair", init<const std::string&, const ExtendibleValueStoreRef&>())
    ///const std::string& getKey() const
    .def("getKey", &ExtendibleKeyValueStorePair::getKey, return_value_policy<copy_const_reference>())
  ;
}

void exportLayeredValueStore() {
  using namespace boost::python;
  using namespace sm::value_store;
  
  class_<LayeredValueStore, bases<ValueStoreRef>>("LayeredValueStore", init<>())
    .def(init<LayeredValueStore>())
    .def(init<LayeredValueStore::SharedPtr>())
    .def(init<sm::PropertyTree>())
    //void add(ValueStoreRef & p)
    .def<void (LayeredValueStore::*)(ValueStoreRef &)>("add", &LayeredValueStore::add)
  ;
}

void exportPrefixedValueStore() {
  using namespace boost::python;
  using namespace sm::value_store;
  
  enum_<PrefixedValueStore::PrefixMode>("PrefixMode")
  .value("ADD", PrefixedValueStore::PrefixMode::ADD)
  .value("REMOVE", PrefixedValueStore::PrefixMode::REMOVE)
  ;

  class_<PrefixedValueStore, bases<ValueStoreRef>>("PrefixedValueStore", init<const ValueStoreRef&, PrefixedValueStore::PrefixMode, const std::string&>());
}
