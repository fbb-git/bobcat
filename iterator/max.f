template <typename Type>
inline Iterator<Type> Iterator<Type>::max()
{
    return Iterator<Type>(std::numeric_limits<Type>::max());
}
