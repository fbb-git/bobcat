template<typename Value>
template <typename InputIterator>
inline HashString<Value>::HashString(InputIterator first, 
                                     InputIterator beyond)
:
    BaseClass(first, beyond)
{}
