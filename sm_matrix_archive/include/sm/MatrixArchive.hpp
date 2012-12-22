#ifndef SM_AMA_MATRIX_IO_HPP
#define SM_AMA_MATRIX_IO_HPP

#include <string>
#include <map>
#include <set>
#include <boost/static_assert.hpp>
#include <boost/filesystem.hpp>
#include <sm/assert_macros.hpp>
#include <Eigen/Core>


// This code only works if a double is 8 bytes.
BOOST_STATIC_ASSERT(sizeof(double) == 8); 
BOOST_STATIC_ASSERT(sizeof(std::string::value_type) == 1); 


namespace sm { 

    SM_DEFINE_EXCEPTION(MatrixArchiveException,std::runtime_error);
    
    class MatrixArchive{
    public:
      typedef std::map< std::string, Eigen::MatrixXd > matrix_map_t;

      MatrixArchive();
      ~MatrixArchive();
    
      // clears the matrix archive.
      void clear();
      // clears a specific value from the archive.
      void clear(std::string const & entryName);
      // gets the number of matrices in the archive.
      size_t size() const;

      matrix_map_t::const_iterator begin() const;
      matrix_map_t::const_iterator end() const;
      matrix_map_t::const_iterator find(std::string const & name) const;
    
      // Loads matrices from a file into the archive.
      void load(const std::string & amaFilePath);
      void load(boost::filesystem::path const & amaFilePath);
      void load(boost::filesystem::path const & amaFilePath, std::set<std::string> const & validNames);

      // Saves matrices from a file into the archive.
      void save(const std::string & amaFilePath) const;
      void save(boost::filesystem::path const & amaFilePath) const;
      void save(boost::filesystem::path const & amaFilePath, std::set<std::string> const & validNames) const;
      void save(std::ostream & fout, std::set<std::string> const & validNames) const;

      // Appends matrices to a file.
      void append(std::string const & amaFilePath) const;
      void append(boost::filesystem::path const & amaFilePath) const;
      void append(boost::filesystem::path const & amaFilePath, std::set<std::string> const & validNames) const;

      template<typename Derived>
      void setMatrix(std::string const & matrixName, Eigen::MatrixBase<Derived> const & matrix);
      template<typename Derived>
      void setVector(std::string const & matrixName, Eigen::MatrixBase<Derived> const & matrix);

      void setMatrixXd(std::string const & matrixName, Eigen::MatrixXd const & matrix);
      void setVectorXd(std::string const & matrixName, Eigen::VectorXd const & matrix);

      void setScalar(std::string const & scalarName, double scalar);

      void getMatrix(std::string const & matrixName, Eigen::MatrixXd & outMatrix) const;
      void getVector(std::string const & vectorName, Eigen::VectorXd & outVector) const;
      void getScalar(std::string const & scalarName, double & outScalar) const;


      bool isSystemLittleEndian() const;

      size_t maxNameSize();
    private:
      static const size_t s_fixedNameSize;
      static const char s_magicCharStart;
      static const char s_magicCharEnd;
      void writeMatrix(std::ostream & fout, std::string const & name, Eigen::MatrixXd const & matrix) const;
      void writeMatrixSwapBytes(std::ostream & fout, std::string const & name, Eigen::MatrixXd const & matrix) const;

      void readMatrix(std::istream & fin, std::string & name, Eigen::MatrixXd & matrix) const;
      void readMatrixSwapBytes(std::istream & fin, std::string & name, Eigen::MatrixXd & matrix) const;

      void validateName(std::string const & name, sm::source_file_pos const & sfp) const;
    
      matrix_map_t m_values;
    
    }; // end class MatrixArchive

    template<typename Derived>
    void MatrixArchive::setMatrix(std::string const & matrixName, Eigen::MatrixBase<Derived> const & matrix)
    {
      validateName(matrixName, SM_SOURCE_FILE_POS);
      m_values[matrixName] = matrix;    
    }
  
    template<typename Derived>
    void MatrixArchive::setVector(std::string const & vectorName, Eigen::MatrixBase<Derived> const & vector)
    {
      SM_ASSERT_EQ(MatrixArchiveException, vector.cols(),1, "The input must be a column vector");
      validateName(vectorName, SM_SOURCE_FILE_POS);
      m_values[vectorName] = vector;
    }


  } // end namespace sm


#endif



