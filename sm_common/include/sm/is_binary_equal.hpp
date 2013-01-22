#ifndef SM_IS_BINARY_EQUAL_HPP
#define SM_IS_BINARY_EQUAL_HPP

namespace sm {
    
    template<typename T>
    inline bool isBinaryEqual(const T * t1, const T * t2)
    {
        if(t1)
        {
            return t1->isBinaryEqual(*t2);
        }
        else
        {
            return t2 == NULL;
        }
    }

    template<typename T>
    inline bool isBinaryEqual(const boost::shared_ptr<T> & t1, const boost::shared_ptr<T> & t2)
    {
        if(t1)
        {
            return t1->isBinaryEqual(*t2);
        }
        else
        {
            return t2.get() == NULL;
        }
    }


} // namespace sm


#endif /* SM_IS_BINARY_EQUAL_HPP */
