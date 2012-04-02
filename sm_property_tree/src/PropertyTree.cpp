#include <sm/PropertyTree.hpp>
#include <sm/string_routines.hpp>
#include <sm/PropertyTreeImplementation.hpp>

namespace sm {
  
  PropertyTree::PropertyTree(boost::shared_ptr<PropertyTreeImplementation> imp, const std::string & baseNamespace) : 
    _imp(imp), _namespace(ensureTrailingBackslash(baseNamespace))
  {
    if(_namespace.size() > 0 && _namespace[0] != '/')
      _namespace = "/" + _namespace;
  }
  
  PropertyTree::PropertyTree(const PropertyTree & parent, const std::string & childNamespace) :
    _imp(parent._imp), _namespace(ensureTrailingBackslash(parent._namespace + childNamespace))
  {
    if(_namespace.size() > 0 && _namespace[0] != '/')
      _namespace = "/" + _namespace;    
  }


  PropertyTree::~PropertyTree()
  {

  }

  // \todo This function could do more name checking.
  std::string PropertyTree::buildQualifiedKeyName(const std::string & key) const
  {
    SM_ASSERT_GT(InvalidKeyException, key.size(), 0, "The key must contain characters");
    if(key[0] == '/')
      {
	// The requested key is in the global namespace
	SM_ASSERT_GT(InvalidKeyException, key.size(), 1, "The key \"" << key << "\" is in the global namespace but does not contain a variable name");
	return key;
      }
    else
      {
	return _namespace + key;
      }
  }

    
  double PropertyTree::getDouble(const std::string & key) const
  {
    return _imp->getDouble(buildQualifiedKeyName(key));
  }

  double PropertyTree::getDouble(const std::string & key, double defaultValue) const
  {
    return _imp->getDouble(buildQualifiedKeyName(key), defaultValue);
  }

  
  int PropertyTree::getInt(const std::string & key) const
  {
    return _imp->getInt(buildQualifiedKeyName(key));
  }

  int PropertyTree::getInt(const std::string & key, int defaultValue) const
  {
    return _imp->getInt(buildQualifiedKeyName(key),defaultValue);
  }

  
  bool PropertyTree::getBool(const std::string & key) const
  {
    return _imp->getBool(buildQualifiedKeyName(key));
  }

  bool PropertyTree::getBool(const std::string & key, bool defaultValue) const
  {
    return _imp->getBool(buildQualifiedKeyName(key), defaultValue);
  }

  
  std::string PropertyTree::getString(const std::string & key) const
  {
    return _imp->getString(buildQualifiedKeyName(key));
  }

  std::string PropertyTree::getString(const std::string & key, const std::string & defaultValue) const
  {
    return _imp->getString(buildQualifiedKeyName(key), defaultValue);
  }

  
  bool PropertyTree::doesKeyExist(const std::string & key) const
  {
    return _imp->doesKeyExist(buildQualifiedKeyName(key));
  }

  
} // namespace sm
