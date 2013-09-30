template<typename Value>
inline HashStringCase<Value>::HashStringCase(HashStringCase &&tmp)
:
    BaseClass(std::move(tmp)) 
{}
