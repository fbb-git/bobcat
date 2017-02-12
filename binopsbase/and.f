
template <typename Derived, typename Rhs>
Derived &operator&=(BinopsBase<Derived> &lhs, Rhs const &rhs) 
{
    Derived tmp{ Derived{der(lhs)} &= rhs };
    tmp.swap(der(lhs));
    return der(lhs);
}

template <typename Derived, typename Rhs>
Derived operator&(BinopsBase<Derived> &&lhs, Rhs const &rhs)
{
    return der(std::move(lhs)) &= rhs;
}

template <typename Derived, typename Rhs>
Derived operator&(BinopsBase<Derived> const &lhs, Rhs const &rhs)
{
    return Derived{der(lhs)} &= rhs;
}

