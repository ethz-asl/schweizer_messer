#ifndef BOOST_SERIALIZATION_HPP
#define BOOST_SERIALIZATION_HPP

#include <fstream>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/filesystem.hpp>
#include <sm/assert_macros.hpp>
// BOOST_SERIALIZATION_NVP
#include <boost/archive/xml_oarchive.hpp>
#include <boost/archive/xml_iarchive.hpp>


// Save and load using boost serailization
namespace sm { namespace boost_serialization {

    template<typename T>
    void save(T & object, ::boost::filesystem::path const & filename)
    {
      std::ofstream ofs(filename.string().c_str(), std::ios::binary);
      SM_ASSERT_TRUE(std::runtime_error,ofs.good(), "Unable to open file " << filename << " for writing");
      ::boost::archive::binary_oarchive oa(ofs);
    
      oa << object;
    }

    template<typename T>
    void load(T & object, ::boost::filesystem::path const & filename)
    {
      std::ifstream ifs(filename.string().c_str(), std::ios::binary);
      SM_ASSERT_TRUE(std::runtime_error,ifs.good(), "Unable to open file " << filename << " for reading");
      ::boost::archive::binary_iarchive ia(ifs);
    
      ia >> object;

    }

    template<typename T>
    void save_xml(T & object, std::string topLevelXmlTag, ::boost::filesystem::path const & filename)
    {
      std::ofstream ofs(filename.string().c_str());
      SM_ASSERT_TRUE(std::runtime_error,ofs.good(), "Unable to open file " << filename << " for writing");
      ::boost::archive::xml_oarchive oa(ofs);
      if(topLevelXmlTag.size() == 0)
	{
	  topLevelXmlTag = "object";
	}

      oa << ::boost::serialization::make_nvp(topLevelXmlTag.c_str(), object);

    }

    template<typename T>
    void load_xml(T & object, std::string topLevelXmlTag, ::boost::filesystem::path const & filename)
    {
      std::ifstream ifs(filename.string().c_str());
      SM_ASSERT_TRUE(std::runtime_error,ifs.good(), "Unable to open file " << filename << " for reading");

      ::boost::archive::xml_iarchive ia(ifs);

      if(topLevelXmlTag.size() == 0)
	{
	  topLevelXmlTag = "object";
	}
   
      ia >> ::boost::serialization::make_nvp(topLevelXmlTag.c_str(), object);

    }


    
    }} // namespace sm::boost_serialization


#endif /* ASRL_SERIALIZATION_HPP */
