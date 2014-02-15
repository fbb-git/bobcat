template <typename Type>
inline bool Iterator<Type>::operator==(Iterator<Type> const &rhs) const
{
    return d_value == rhs.d_value;
}
