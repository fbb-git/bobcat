template <typename Type>
inline Type &Iterator<Type>::operator*()
{
    *d_type = d_value;
    return *d_type;
}
