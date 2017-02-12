template <typename Derived>
inline void BinopsBase<Derived>::eWrap(std::istream &in)
{
    der(*this).extract(in);
}

template <typename Derived>
inline std::istream &operator>>(std::istream &in, BinopsBase<Derived> &rhs)
{
    rhs.eWrap(in);
    return in;
}
