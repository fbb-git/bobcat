template <typename Type>
inline bool operator!=(CSV::const_iterator<Type> const &lhs,
                       CSV::const_iterator<Type> const &rhs)
{
    return not (lhs == rhs);
}
