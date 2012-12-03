#include <sm/pose_graph/Edge.hpp>


namespace sm { namespace pose_graph {

        /// 
        /// Default constructor. The id is set to zero.
        ///
        Edge::Edge() : _type(0)
        {
            _T_to_from.reset(new transformation_t);
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
            _id(id),
            _to(to),
            _from(from),
            _type(0)
        {
            _T_to_from.reset(new transformation_t(T_to_from));
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
                _T_to_from.reset(new transformation_t(*rhs._T_to_from));
                _id = rhs._id;
                _to = rhs._to;
                _from = rhs._from;
            }
        }


        Edge & Edge::operator=(const Edge & rhs)
        {
            if(&rhs != this)
            {
                *_T_to_from = *rhs._T_to_from;
                _id = rhs._id;
                _to = rhs._to;
                _from = rhs._from;
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
            _id = id;
        }

        /// 
        /// An accessor to the get edge's unique id
        ///
        /// @return The unique id identifying the edge.
        ///
        EdgeId Edge::id() const
        {
            return _id;
        }

        /// 
        ///
        /// @return the unique id of the "to" end of the edge 
        ///
        VertexId Edge::to() const
        {
            return _to;
        }

        /// 
        ///
        /// @return The unique id of the "from" end of the edge 
        ///
        VertexId Edge::from() const
        {
            return _from;
        }

        /// 
        /// 
        /// @return The transformation stored in the edge
        ///
        const transformation_t & Edge::T_to_from() const
        {
            return *_T_to_from;
        }      
      
        /// 
        /// 
        /// @return The transformation stored in the edge
        ///
        transformation_t & Edge::T_to_from()
        {
            return *_T_to_from;
        }      


        void Edge::set_T_to_from(const transformation_t & T_to_from)
        {
            *_T_to_from = T_to_from;
        }
      
        
        /// \brief get the edge type
        boost::uint64_t Edge::type() const
        {
            return _type;
        }
        
        /// \brief set the edge type
        void Edge::setType(boost::uint64_t type)
        {
            _type = type;
        }

    }} // namespace asrl::pose_graph
