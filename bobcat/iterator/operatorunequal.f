template <typename Type>
inline bool Iterator<Type>::operator!=(Iterator const &rhs) const
{
    return d_value != rhs.d_value;
}
