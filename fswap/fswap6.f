    // overloaded fswap function swapping pointers
    //
template <typename Type>
inline void fswap(Type *&lhs, Type *&rhs)
{
    std::swap(lhs, rhs);
}
