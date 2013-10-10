template<typename Value>
inline HashCharCasePtr<Value>::HashCharCasePtr(HashCharCasePtr &&tmp)
:
    BaseClass(std::move(tmp))
{}
