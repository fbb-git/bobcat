template <typename Type>
inline Iterator<Type> Iterator<Type>::min()
{
    return Iterator<Type>(std::numeric_limits<Type>::min());
}
