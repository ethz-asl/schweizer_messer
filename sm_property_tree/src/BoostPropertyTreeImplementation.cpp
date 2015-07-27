#include <sm/BoostPropertyTreeImplementation.hpp>
#include <boost/make_shared.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/info_parser.hpp>

namespace sm {
  
  BoostPropertyTreeImplementation::BoostPropertyTreeImplementation()
  {

  }

  BoostPropertyTreeImplementation::BoostPropertyTreeImplementation(const boost::property_tree::ptree& ptree)
  : _ptree(ptree)
  {
  }

  BoostPropertyTreeImplementation::~BoostPropertyTreeImplementation()
  {

  }


  double BoostPropertyTreeImplementation::getDouble(const std::string & key) const
  {
    return get<double>(key);
  }

  double BoostPropertyTreeImplementation::getDouble(const std::string & key, double defaultValue) const
  {
    return get<double>(key,defaultValue);
  }

  double BoostPropertyTreeImplementation::getDouble(const std::string & key, double defaultValue)
  {
    return get<double>(key,defaultValue);
  }

  int BoostPropertyTreeImplementation::getInt(const std::string & key) const
  {
    return get<int>(key);
  }

  int BoostPropertyTreeImplementation::getInt(const std::string & key, int defaultValue) const
  {
    return get<int>(key, defaultValue);
  }

  int BoostPropertyTreeImplementation::getInt(const std::string & key, int defaultValue) 
  {
    return get<int>(key, defaultValue);
  }


  bool BoostPropertyTreeImplementation::getBool(const std::string & key) const
  {
    return get<bool>(key);
  }

  bool BoostPropertyTreeImplementation::getBool(const std::string & key, bool defaultValue) const
  {
    return get<bool>(key, defaultValue);
  }

 bool BoostPropertyTreeImplementation::getBool(const std::string & key, bool defaultValue) 
  {
    return get<bool>(key, defaultValue);
  }


  std::string BoostPropertyTreeImplementation::getString(const std::string & key) const
  {
    return get<std::string>(key);
  }

  std::string BoostPropertyTreeImplementation::getString(const std::string & key, const std::string & defaultValue) const
  {
    return get<std::string>(key, defaultValue);
  }

  std::string BoostPropertyTreeImplementation::getString(const std::string & key, const std::string & defaultValue) 
  {
    return get<std::string>(key, defaultValue);
  }


  bool BoostPropertyTreeImplementation::doesKeyExist(const std::string & key) const
  {
    boost::optional<std::string> val = _ptree.get<std::string>(boost::property_tree::ptree::path_type(key.c_str(),'/'));
    
    return (bool)val;
  }


  void BoostPropertyTreeImplementation::loadXml(const boost::filesystem::path & fileName)
  {
    boost::property_tree::read_xml(fileName.string(), _ptree);
  }

  void BoostPropertyTreeImplementation::saveXml(const boost::filesystem::path & fileName) const
  {
    boost::property_tree::write_xml(fileName.string(), _ptree);
  }
 
  void BoostPropertyTreeImplementation::loadIni(const boost::filesystem::path & fileName)
  {
    boost::property_tree::read_ini(fileName.string(), _ptree);
  }

  void BoostPropertyTreeImplementation::saveIni(const boost::filesystem::path & fileName) const
  {
    boost::property_tree::write_ini(fileName.string(), _ptree);
  }


  void BoostPropertyTreeImplementation::loadInfo(const boost::filesystem::path & fileName)
  {
    boost::property_tree::read_info(fileName.string(), _ptree);
  }

  void BoostPropertyTreeImplementation::saveInfo(const boost::filesystem::path & fileName) const
  {
    boost::property_tree::write_info(fileName.string(), _ptree);
  }

  void BoostPropertyTreeImplementation::setDouble(const std::string & key, double value)
  {
    set<double>(key,value);
  }

  void BoostPropertyTreeImplementation::setInt(const std::string & key, int value)
  {
    set<int>(key,value);
  }

  void BoostPropertyTreeImplementation::setBool(const std::string & key, bool value)
  {
    set<bool>(key,value);
  }

  void BoostPropertyTreeImplementation::setString(const std::string & key, const std::string & value)
  {
    set<std::string>(key,value);
  }

  BoostPropertyTreeImplementation::iterator BoostPropertyTreeImplementation::begin()
  {
    return _ptree.begin();
  }

  BoostPropertyTreeImplementation::const_iterator BoostPropertyTreeImplementation::begin() const
  {
    return _ptree.begin();
  }

  BoostPropertyTreeImplementation::iterator BoostPropertyTreeImplementation::end()
  {
    return _ptree.end();
  }

  BoostPropertyTreeImplementation::const_iterator BoostPropertyTreeImplementation::end() const
  {
    return _ptree.end();
  }


  const std::vector<KeyPropertyTreePair> sm::BoostPropertyTreeImplementation::getChildren() const {
    return const_cast<BoostPropertyTreeImplementation*>(this)->getChildren();
  }

  std::vector<KeyPropertyTreePair> sm::BoostPropertyTreeImplementation::getChildren() {
    std::vector<KeyPropertyTreePair> ret;
    for(auto& p : _ptree){
      ret.push_back({p.first, PropertyTree(boost::make_shared<BoostPropertyTreeImplementation>(p.second), "")});
    }
    return ret;
  }


  /*
   * copied from http://stackoverflow.com/questions/8154107/how-do-i-merge-update-a-boostproperty-treeptree :
   */

  template<typename T>
  void traverse_recursive(const boost::property_tree::ptree::path_type &childPath, const boost::property_tree::ptree &child, T method)
  {
    using boost::property_tree::ptree;

    method(childPath, child);
    for(ptree::const_iterator it=child.begin();it!=child.end();++it) {
      ptree::path_type curPath = childPath / ptree::path_type(it->first);
      traverse_recursive(curPath, it->second, method);
    }
  }

  void updateOnly(boost::property_tree::ptree &dest, const boost::property_tree::ptree::path_type &childPath, const boost::property_tree::ptree &child) {
    if(child.data().empty() || child.data().find_first_not_of(" \n\t\r") == std::string::npos) return;
    if(!dest.get_optional<std::string>(childPath)) {
      throw PropertyTree::KeyNotFoundException(std::string("Could not find the destination '") + childPath.dump() + "' to update with '" + child.data() + "'.");
    }
    dest.put(childPath, child.data());
  }
  void merge(boost::property_tree::ptree &dest, const boost::property_tree::ptree::path_type &childPath, const boost::property_tree::ptree &child) {
    dest.put(childPath, child.data());
  }

  template<typename T>
  void traverse(const boost::property_tree::ptree &parent, T method)
  {
    traverse_recursive("", parent, method);
  }

  void BoostPropertyTreeImplementation::update(const BoostPropertyTreeImplementation & with, bool createIfNecessary){
    using namespace boost;
    traverse(with._ptree, createIfNecessary ? bind(merge, boost::ref(_ptree), _1, _2) : bind(updateOnly, boost::ref(_ptree), _1, _2));
  }
} // namespace sm
