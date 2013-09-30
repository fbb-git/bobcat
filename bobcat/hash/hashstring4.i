template<typename Value>
inline HashString<Value> &HashString<Value>::operator=(HashString &&tmp)
{
    static_cast<BaseClass &>(*this) = std::move(tmp);
    return *this;
}
