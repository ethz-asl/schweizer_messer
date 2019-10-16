#include <numpy_eigen/boost_python_headers.hpp>
#include <sm/BoostPropertyTree.hpp>
#include <sm/BoostPropertyTreeLoader.hpp>

double getDouble(const sm::ConstPropertyTree * p, const std::string & key) {
  return p->getDouble(key);
}

double getDoubleDefault(sm::ConstPropertyTree * p, const std::string & key, double defaultValue) {
  return p->getDouble(key, defaultValue);
}

int getInt(const sm::ConstPropertyTree * p, const std::string & key) {
  return p->getInt(key);
}

int getIntDefault(sm::ConstPropertyTree * p, const std::string & key, int defaultValue) {
  return p->getInt(key, defaultValue);
}

bool getBool(const sm::ConstPropertyTree * p, const std::string & key) {
  return p->getBool(key);
}

bool getBoolDefault(sm::ConstPropertyTree * p, const std::string & key, bool defaultValue) {
  return p->getBool(key, defaultValue);
}

std::string getString(const sm::ConstPropertyTree * p, const std::string & key) {
  return p->getString(key);
}

std::string getStringDefault(sm::ConstPropertyTree * p, const std::string & key, const std::string & defaultValue) {
  return p->getString(key, defaultValue);
}

void exportPropertyTree() {
  using namespace boost::python;
  using namespace sm;

  class_<ConstPropertyTree>("ConstPropertyTree", init<const ConstPropertyTree &, const std::string &>("ConstPropertyTree(ConstPropertyTree parent, string childNamespace)"))
      .def("getChild", &PropertyTree::getChild)
      .def("getInt", &getInt).def("getIntDefault", &getIntDefault)
      .def("getString", &getString)
      .def("getStringDefault", &getStringDefault)
      .def("getBool", &getBool).def("getBoolDefault", &getBoolDefault)
      .def("getDouble", &getDouble).def("getDoubleDefault", &getDoubleDefault)
      .def("doesKeyExist", &ConstPropertyTree::doesKeyExist);

  class_<PropertyTree, bases<ConstPropertyTree>>("PropertyTree", init<const PropertyTree &, const std::string &>("PropertyTree(PropertyTree parent, string childNamespace)"))
      .def("getChild", &PropertyTree::getChild)
      .def("getOrCreateInt", static_cast<int(PropertyTree::*)(const std::string &, int)>(&PropertyTree::getInt))
      .def("getOrCreateString", static_cast<std::string(PropertyTree::*)(const std::string &, const std::string&)>(&PropertyTree::getString))
      .def("getOrCreatetBool", static_cast<bool(PropertyTree::*)(const std::string &, bool)>(&PropertyTree::getBool))
      .def("getOrCreateDouble", static_cast<double(PropertyTree::*)(const std::string &, double)>(&PropertyTree::getDouble))
      .def("setInt", &PropertyTree::setInt)
      .def("setBool", &PropertyTree::setBool)
      .def("setString", &PropertyTree::setString)
      .def("setDouble", &PropertyTree::setDouble)
      ;

  class_<BoostPropertyTree, bases<PropertyTree> >("BoostPropertyTree", init<>())
      .def(init<std::string>("BoostPropertyTree( string baseNamespace )"))
      .def("loadXml", &BoostPropertyTree::loadXmlStr)
      .def("saveXml", &BoostPropertyTree::saveXmlStr)
      .def("loadIni", &BoostPropertyTree::loadIniStr)
      .def("saveIni", &BoostPropertyTree::saveIniStr)
      .def("loadInfo", &BoostPropertyTree::loadInfoStr)
      .def("saveInfo", &BoostPropertyTree::saveInfoStr)
      .def("update",
           static_cast<void(BoostPropertyTree::*)(const BoostPropertyTree&, bool, bool)>(
             &BoostPropertyTree::update
           ),
          "update(BoostPropertyTree & with, bool createIfNecessary, bool ignoreEmptyUpdates), update the property tree with another one")
      .def("updateWithEmptyUpdates",
           static_cast<void(BoostPropertyTree::*)(const BoostPropertyTree&, bool)>(
             &BoostPropertyTree::update
           ),
          "updateWithEmptyUpdates(BoostPropertyTree & with, bool createIfNecessary), update the property tree with another one, not ignoring empty updates")
      .def("updateOrCreate",
           static_cast<void(BoostPropertyTree::*)(const BoostPropertyTree&)>(
             &BoostPropertyTree::update
           ),
           "updateOrCreate(BoostPropertyTree & with), update the property tree with another one, creating nodes if necessary")
     ;
}

void exportPropertyTreeLoader() {
  using namespace boost::python;
  using namespace sm;
  
  class_<BoostPropertyTreeLoader>("BoostPropertyTreeLoader", init<>())
    ///sm::BoostPropertyTree readFilesAndMergeIntoPropertyTree(const std::string& commaSeparatedFileList)
    .def<sm::BoostPropertyTree(BoostPropertyTreeLoader::*)(const std::string&)>("readFilesAndMergeIntoPropertyTree", &BoostPropertyTreeLoader::readFilesAndMergeIntoPropertyTree)
  ;
}
