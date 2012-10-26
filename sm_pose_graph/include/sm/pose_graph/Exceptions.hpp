/*
 * Adapted from the Willow Garage pose_graph package by Paul Furgale on October 22, 2010.
 * 
 * Original version:
 *
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
 */


/************************************************************ 
 * Namespace and includes
 ************************************************************/

#ifndef SM_POSE_GRAPH_EXCEPTION_HPP
#define SM_POSE_GRAPH_EXCEPTION_HPP

//#include <sm/Id.hpp>
#include <boost/format.hpp>
#include <stdexcept>
#include <string>

namespace sm { namespace pose_graph {

using boost::format;
using std::string;

/// A base class for all pose_graph exceptions; provides a handy boost::format parent constructor
class PoseGraphException: public std::logic_error
{
public:
  PoseGraphException (const format& error_string) : std::logic_error(error_string.str()) {};
  PoseGraphException (const char* str) : std::logic_error(str) {};
  PoseGraphException (const std::string & str) : std::logic_error(str) {};
};


/// Exception for unknown VertexId
struct UnknownVertexIdException: public PoseGraphException
{
  UnknownVertexIdException (const VertexId id): 
    PoseGraphException(format("Unknown vertex id %1%") % id), id(id) {}
  const VertexId id;
};

/// Exception for unknown EdgeId
struct UnknownEdgeIdException: public PoseGraphException
{
  UnknownEdgeIdException (const EdgeId id): 
    PoseGraphException(format("Unknown edge id %1%") % id), id(id) {}
  const EdgeId id;
};


/// Exception for trying to add a VertexId that already exists
struct DuplicateVertexIdException: public PoseGraphException
{
  DuplicateVertexIdException (const VertexId id):
    PoseGraphException(format("Vertex %1% already exists") % id), id(id) {}
  const VertexId id;
};

/// Exception for performing an operation with an unknown sensor frame id
struct UnknownSensorFrameId: public PoseGraphException
{
  UnknownSensorFrameId (const std::string & frameId ):
    PoseGraphException(format("Unknown frame id: %1%") % frameId), frameId(frameId) {}
  const std::string & frameId;
};



/// Exception for trying to add an EdgeId that already exists
struct DuplicateEdgeIdException: public PoseGraphException
{
  DuplicateEdgeIdException (const EdgeId id):
    PoseGraphException(format("Edge %1% already exists") % id), id(id) {}
  const EdgeId id;
};

struct NoPathFound : public PoseGraphException
{
  NoPathFound(const VertexId from, const VertexId to) :
    PoseGraphException(format("No path found between vertex %1% and vertex %2%") % from % to), from(from), to(to) {}
  const VertexId from;
  const VertexId to;
};
  }} // namespace sm::pose_graph

#endif // POSE_GRAPH_EXCEPTION_H
