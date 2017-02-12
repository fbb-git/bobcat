template <typename Derived>
constexpr Derived &der(BinopsBase<Derived> &rhs)
{
    return static_cast<Derived &>(rhs);
}

template <typename Derived>
constexpr Derived const &der(BinopsBase<Derived> const &rhs)
{
    return static_cast<Derived const &>(rhs);
}

template <typename Derived>
constexpr Derived &&der(BinopsBase<Derived> &&rhs)
{
    return static_cast<Derived &&>(rhs);
}
