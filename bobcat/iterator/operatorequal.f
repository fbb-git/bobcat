template <typename Type>
inline bool operator==(Iterator<Type> const &lhs, Iterator<Type> const &rhs)
{
    return lhs.d_value == rhs.d_value;
}
