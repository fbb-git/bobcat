template <typename Type>
inline Type const &Iterator<Type>::operator*() const
{
    *d_type = d_value;
    return *d_type;
}
