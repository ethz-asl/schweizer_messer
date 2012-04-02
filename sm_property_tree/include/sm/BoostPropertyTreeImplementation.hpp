#ifndef SM_BOOST_PROPERTY_TREE_IMPLEMENTATION_HPP
#define SM_BOOST_PROPERTY_TREE_IMPLEMENTATION_HPP

#include "PropertyTreeImplementation.hpp"
#include "PropertyTree.hpp"
#include <boost/property_tree/ptree.hpp>
#include <boost/filesystem/path.hpp>
#include <typeinfo>
namespace sm {
  
  class BoostPropertyTreeImplementation : public PropertyTreeImplementation
  {
  public:
    BoostPropertyTreeImplementation();
    virtual ~BoostPropertyTreeImplementation();

    virtual double getDouble(const std::string & key) const;
    virtual double getDouble(const std::string & key, double defaultValue) const;

    virtual int getInt(const std::string & key) const;
    virtual int getInt(const std::string & key, int defaultValue) const;

    virtual bool getBool(const std::string & key) const;
    virtual bool getBool(const std::string & key, bool defaultValue) const;

    virtual std::string getString(const std::string & key) const;
    virtual std::string getString(const std::string & key, const std::string & defaultValue) const;

    virtual bool doesKeyExist(const std::string & key) const;

    void loadXml(const boost::filesystem::path & fileName);
    void saveXml(const boost::filesystem::path & fileName) const;
 
    void loadJson(const boost::filesystem::path & fileName);
    void saveJson(const boost::filesystem::path & fileName) const;
 
    void loadIni(const boost::filesystem::path & fileName);
    void saveIni(const boost::filesystem::path & fileName) const;

    void loadInfo(const boost::filesystem::path & fileName);
    void saveInfo(const boost::filesystem::path & fileName) const;

  private:

    template<typename T>
    T get(const std::string & key) const;

    template<typename T>
    T get(const std::string & key, const T & defaultValue) const;
    
    boost::property_tree::ptree _ptree;

  };

  template<typename T>
  T BoostPropertyTreeImplementation::get(const std::string & key) const
  {
    using namespace boost::property_tree;
    T rval;
    try 
      {
	rval = _ptree.get<T>(ptree::path_type(key.substr(1),'/'));
      }
    catch(const ptree_bad_data & e)
      {
	SM_THROW(PropertyTree::InvalidValueException, "Unable to get the value as type " << typeid(T).name() << ": " << e.what());
      }
    catch(const ptree_bad_path & e)
      {
	SM_THROW(PropertyTree::InvalidKeyException, "The key \"" << key << "\" was invalid: " << e.what());
      }

    return rval;
  }
  
  template<typename T>
  T BoostPropertyTreeImplementation::get(const std::string & key, const T & defaultValue) const
  {
    boost::optional<T> val = _ptree.get<T>(boost::property_tree::ptree::path_type(key.substr(1),'/'));
    if(val)
      {
	return *val;
      }
    else
      {
	return defaultValue;
      }
  }


} // namespace sm


#endif /* SM_BOOST_PROPERTY_TREE_IMPLEMENTATION_HPP */
