/*
 * Adapted from the Willow Garage pose_graph package by Paul Furgale on October 22, 2010.
 * 
 * Original file:
 * Copyright (c) 2008, Willow Garage, Inc.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef SM_ID_HPP
#define SM_ID_HPP


#include <boost/cstdint.hpp>
#include <iostream>

namespace sm {

  typedef boost::uint64_t id_type;

  ///
  /// \class Id
  /// \brief superclass for stronly-typed uint64 ids
  ///
  /// Usage:
  /// \code
  /// // MyId is a stronly typed Id for my object.
  /// class MyId : public Id
  /// {
  /// public:
  ///
  ///   explicit MyId (id_type id = -1) : Id(id) {}
  ///
  ///   template<class Archive>
  ///   void serialize(Archive & ar, const unsigned int version)
  ///   {
  ///     ar & id_;
  ///   }
  /// };
  /// \endcode
  ///
  class Id
  {
  public:
  
    explicit Id (id_type id) : id_(id) {}

    /// Only for stl use
    Id () : id_(-1) {}

    friend std::ostream& operator<< (std::ostream& str, const Id& n)
    {
      str << n.id_;
      return str;
    }

    bool operator== (const Id& other) const
    {
      return other.id_ == id_;
    }

    bool operator!= (const Id& other) const
    {
      return other.id_ != id_;
    }

    bool operator< (const Id& other) const
    {
      return id_ < other.id_;
    }

    id_type getId () const
    {
      return id_;
    }

    // postincrement.
    void operator++ (int unused)
    {
      id_++;
    }

    // preincrement
    Id & operator++ ()
    {
      ++id_;
      return (*this);
    }

    Id& operator= (const Id& other)
    {
      id_ = other.id_;
      return *this;
    }

    bool isSet() const
    {
      return id_ != id_type(-1);
    }

    id_type value() const
    {
      return id_;
    }
  protected:
    id_type id_;
  
  };

} // namespace aslam


#define SM_DEFINE_ID(IdTypeName)					\
  class IdTypeName : public aslam::Id					\
  {									\
  public:								\
    explicit IdTypeName (aslam::id_type id = -1) : aslam::Id(id) {}	\
									\
    template<class Archive>						\
      void serialize(Archive & ar, const unsigned int version)		\
    {									\
      ar & id_;								\
    }									\
  };

#endif /* SM_ID_HPP */
