template<typename Value>
inline HashCharCasePtr<Value> &HashCharCasePtr<Value>::operator=(
                                                HashCharCasePtr &&tmp)
{
    static_cast<BaseClass &>(*this) = std::move(tmp);
    return *this;
}
