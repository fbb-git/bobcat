template <typename Type>
inline Iterator<Type> &Iterator<Type>::operator--()
{
    --d_value;
    return *this;
}
