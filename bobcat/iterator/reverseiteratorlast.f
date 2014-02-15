template <typename Type>
inline ReverseIterator<Type> ReverseIterator<Type>::last(Type const &value)
{
    return ReverseIterator<Type>(Iterator<Type>::last(value));
}
