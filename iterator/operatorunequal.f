template <typename Type>
inline bool operator!=(Iterator<Type> const &lhs, Iterator<Type> const &rhs)
{
    return not (lhs == rhs);
}
