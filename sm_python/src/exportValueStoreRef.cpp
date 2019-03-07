#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/value_store/ValueStore.hpp>
#include <sm/PropertyTree.hpp>

void exportValueStoreRef()
{
    using namespace boost::python;
    using namespace sm::value_store;
    /// brief create a value store reference pointing to a fresh empty value store (based on @see sm::BoostPropertyTree)
    /// ValueStoreRef();
    class_<ValueStoreRef, boost::shared_ptr<ValueStoreRef>>("ValueStoreRef", init<>())
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
    ;
}