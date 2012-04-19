#include <sm/BoostPropertyTree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <sm/BoostPropertyTreeImplementation.hpp>

namespace sm {
  
  BoostPropertyTree::BoostPropertyTree(const std::string & baseNamespace) :
    PropertyTree(boost::shared_ptr<PropertyTreeImplementation>(new BoostPropertyTreeImplementation), baseNamespace)
  {

  }

  BoostPropertyTree::~BoostPropertyTree()
  {

  }

  void BoostPropertyTree::loadXml(const boost::filesystem::path & fileName)
  {
    dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->loadXml(fileName);
  }

  void BoostPropertyTree::saveXml(const boost::filesystem::path & fileName) const
  {
    dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->saveXml(fileName);
  }

 
  void BoostPropertyTree::loadJson(const boost::filesystem::path & fileName)
  {
    dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->loadJson(fileName);
  }

  void BoostPropertyTree::saveJson(const boost::filesystem::path & fileName) const
  {
    dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->saveJson(fileName);
  }

 
  void BoostPropertyTree::loadIni(const boost::filesystem::path & fileName)
  {
    dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->loadIni(fileName);
  }

  void BoostPropertyTree::saveIni(const boost::filesystem::path & fileName) const
  {
    dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->saveIni(fileName);
  }


  void BoostPropertyTree::loadInfo(const boost::filesystem::path & fileName)
  {
    dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->loadInfo(fileName);
  }

  void BoostPropertyTree::saveInfo(const boost::filesystem::path & fileName) const
  {
    dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->saveInfo(fileName);
  }


    BoostPropertyTree::iterator BoostPropertyTree::begin()
    {
      dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->begin();
    }

    BoostPropertyTree::const_iterator BoostPropertyTree::begin() const
    {
      dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->begin();
    }

    BoostPropertyTree::iterator BoostPropertyTree::end()
    {
      dynamic_cast<BoostPropertyTreeImplementation*>(_imp.get())->end();
    }

    BoostPropertyTree::const_iterator BoostPropertyTree::end() const
    {
      dynamic_cast<const BoostPropertyTreeImplementation*>(_imp.get())->end();
    }



} // namespace sm
