template <typename Derived>
inline void BinopsBase<Derived>::iWrap(std::ostream &out) const
{
    der(*this).insert(out);
}

template <typename Derived>
inline std::ostream &operator<<(std::ostream &out, BinopsBase<Derived> const &rhs)
{
    rhs.iWrap(out);
    return out;
}
