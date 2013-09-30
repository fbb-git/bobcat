template<typename Value>
inline HashCharPtr<Value>::HashCharPtr(HashCharPtr &&tmp)
:
    BaseClass(std::move(tmp))
{}
