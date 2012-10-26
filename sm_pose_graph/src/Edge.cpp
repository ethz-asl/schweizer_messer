#include <sm/pose_graph/Edge.hpp>


namespace sm { namespace pose_graph {

    /// 
    /// Default constructor. The id is set to zero.
    ///
    Edge::Edge()
    {
      T_to_from_.reset(new transformation_t);
    }

    /// 
    /// Constructor to build a fully initialized edge.
    ///
    /// @param id       The edge id
    /// @param from      The vertex id at the tail of the edge
    /// @param to        The vertex id at the head of the edge
    /// @param T_to_from The uncertain transformation associated with the edge.
    ///
    Edge::Edge(EdgeId id, VertexId to, VertexId from, transformation_t const & T_to_from) :
      id_(id),
      to_(to),
      from_(from)
    {
      T_to_from_.reset(new transformation_t(T_to_from));
    }

    ///
    /// Destructor. 
    ///
    Edge::~Edge()
    {

    }

    Edge::Edge(const Edge & rhs)
    {
      if(&rhs != this)
	{
	  T_to_from_.reset(new transformation_t(*rhs.T_to_from_));
	  id_ = rhs.id_;
	  to_ = rhs.to_;
	  from_ = rhs.from_;
	}
    }


    Edge & Edge::operator=(const Edge & rhs)
    {
      if(&rhs != this)
	{
	  *T_to_from_ = *rhs.T_to_from_;
	  id_ = rhs.id_;
	  to_ = rhs.to_;
	  from_ = rhs.from_;
	}
      return *this;
    }

    /// 
    /// A mutator to set the edge's unique id. This should be used with
    /// caution.
    ///
    /// @param id The edge's unique id. 
    ///
    void Edge::setId(EdgeId id)
    {
      id_ = id;
    }

    /// 
    /// An accessor to the get edge's unique id
    ///
    /// @return The unique id identifying the edge.
    ///
    EdgeId Edge::id() const
    {
      return id_;
    }

    /// 
    ///
    /// @return the unique id of the "to" end of the edge 
    ///
    VertexId Edge::to() const
    {
      return to_;
    }

    /// 
    ///
    /// @return The unique id of the "from" end of the edge 
    ///
    VertexId Edge::from() const
    {
      return from_;
    }

    /// 
    /// 
    /// @return The transformation stored in the edge
    ///
    const transformation_t & Edge::T_to_from() const
    {
      return *T_to_from_;
    }      
      
    /// 
    /// 
    /// @return The transformation stored in the edge
    ///
    transformation_t & Edge::T_to_from()
    {
      return *T_to_from_;
    }      


    void Edge::set_T_to_from(const transformation_t & T_to_from)
    {
      *T_to_from_ = T_to_from;
    }
      

  }} // namespace asrl::pose_graph
