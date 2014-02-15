template <typename Type>
inline Iterator<Type> Iterator<Type>::operator--(int)
{
    Iterator<Type> tmp(d_value--);
    return tmp;
}
