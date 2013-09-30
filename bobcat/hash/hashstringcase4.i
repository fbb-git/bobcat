template<typename Value>
inline HashStringCase<Value> &HashStringCase<Value>::operator=(
                                                HashStringCase &&tmp)
{
    static_cast<BaseClass &>(*this) = std::move(tmp);
    return *this;
}
