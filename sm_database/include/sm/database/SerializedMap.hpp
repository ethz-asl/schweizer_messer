#ifndef SM_SERIALIZED_MAP_HPP
#define SM_SERIALIZED_MAP_HPP

// Because this class is templated, there
// is no shielding anyone from the full set 
// of header files.
#include <boost/filesystem.hpp>
#include <sqlite3.h>
#include <sm/boost/serialization.hpp>
#include <sm/assert_macros.hpp>
#include <sstream>
#include <boost/iostreams/device/array.hpp>
#include <boost/iostreams/stream.hpp>
#include <boost/filesystem.hpp>
#include <string>


namespace sm {
  namespace database {
    SM_DEFINE_EXCEPTION(Exception,std::runtime_error);
    SM_DEFINE_EXCEPTION(SqlException,Exception);
    SM_DEFINE_EXCEPTION(UnknownIdException, Exception);
    SM_DEFINE_EXCEPTION(UnableToOpenDatabaseException, Exception);
    SM_DEFINE_EXCEPTION(InvalidTableNameException, Exception);
    SM_DEFINE_EXCEPTION(InvalidDbNameException, Exception);
    SM_DEFINE_EXCEPTION(NullValueException, Exception);
    
    template<typename T>
    class SerializedMap 
    {
    public:
      typedef T value_t;
      
      SerializedMap(const ::boost::filesystem::path & dbFileName, 
		    const std::string & tableName);
      virtual ~SerializedMap();
      
      ::boost::shared_ptr<T> get(::boost::uint64_t id);      
      void set(::boost::uint64_t id, const ::boost::shared_ptr<T> & value);
      
      const std::string & tableName(){ return _tableName; }
    private:
      void validateTableName();

      ::boost::filesystem::path _dbName;
      std::string _tableName;
      sqlite3 * _db;
      sqlite3_stmt * _iStmt, * _sStmt;
      
    };


  } // namespace database
  
} // namespace sm

#include "implementation/SerializedMap.hpp"

#endif /* SM_SERIALIZED_MAP_HPP */
