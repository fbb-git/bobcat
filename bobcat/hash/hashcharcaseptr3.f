template<typename Value>
template <typename InputIterator>
inline HashCharCasePtr<Value>::HashCharCasePtr(InputIterator first, 
                                               InputIterator beyond)
:
    BaseClass(first, beyond)
{}
