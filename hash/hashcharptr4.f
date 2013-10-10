template<typename Value>
inline HashCharPtr<Value> &HashCharPtr<Value>::operator=(HashCharPtr &&tmp)
{
    static_cast<BaseClass &>(*this) = std::move(tmp);
    return *this;
}
