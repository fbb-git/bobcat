template <typename Type>
inline Type const &Iterator<Type>::operator*() const
{
    return d_value;
//
//    *d_type = d_value;
//    return *d_type;
}
