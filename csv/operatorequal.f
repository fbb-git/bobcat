template <typename Type>
inline bool operator==(CSV::const_iterator<Type> const &lhs,
                       CSV::const_iterator<Type> const &rhs)
{
    return lhs.d_idx == rhs.d_idx && lhs.d_csv == rhs.d_csv;
}
