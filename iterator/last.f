template <typename Type>
inline Iterator<Type> Iterator<Type>::last(Type value)
{
    return Iterator<Type>(++value);
}
