#ifndef SM_PROPERTY_TREE_HPP
#define SM_PROPERTY_TREE_HPP

#include <boost/shared_ptr.hpp>
#include <sm/assert_macros.hpp>

namespace sm {
  // Forward declaration.
  class PropertyTreeImplementation;
  
  class PropertyTree
  {
  public:
    SM_DEFINE_EXCEPTION(Exception, std::runtime_error);
    SM_DEFINE_EXCEPTION(InvalidKeyException, Exception);
    SM_DEFINE_EXCEPTION(InvalidValueException, Exception);
    SM_DEFINE_EXCEPTION(KeyNotFoundException, Exception);

    PropertyTree(boost::shared_ptr<PropertyTreeImplementation> imp, const std::string & baseNamespace = "");
    PropertyTree(const PropertyTree & parent, const std::string & childNamespace);

    virtual ~PropertyTree();
    
    double getDouble(const std::string & key) const;
    double getDouble(const std::string & key, double defaultValue) const;

    int getInt(const std::string & key) const;
    int getInt(const std::string & key, int defaultValue) const;

    bool getBool(const std::string & key) const;
    bool getBool(const std::string & key, bool defaultValue) const;

    std::string getString(const std::string & key) const;
    std::string getString(const std::string & key, const std::string & defaultValue) const;

    bool doesKeyExist(const std::string & key) const;
  private:
    
    boost::shared_ptr<PropertyTreeImplementation> _imp;
    std::string _namespace;
    std::string buildQualifiedKeyName(const std::string & key) const;
  };

} // namespace sm



#endif /* SM_PROPERTY_TREE_HPP */
