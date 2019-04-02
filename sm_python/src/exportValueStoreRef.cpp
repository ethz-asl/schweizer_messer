#include <boost/python.hpp>
#include <boost/core/noncopyable.hpp>

#include <sm/PropertyTree.hpp>
#include <sm/value_store/ValueStore.hpp>
#include <functional>

void exportValueStoreRef()
{
  using namespace boost::python;
  using namespace sm::value_store;

  /// brief create a value store reference pointing to a fresh empty value store (based on @see sm::BoostPropertyTree)
  class_<ValueStoreRef>("ValueStoreRef", init<>())
    .def(init<ValueStoreRef>())
    .def(init<ValueStore::SharedPtr>())
    .def(init<sm::PropertyTree>())
    /// ValueStoreRef getChild(const std::string & key)
    .def("getChild", &ValueStoreRef::getChild)
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
  ;
}
