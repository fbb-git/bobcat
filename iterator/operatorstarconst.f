template <typename Type>
inline Type const &Iterator<Type>::operator*() const
{
    return d_value;
}
