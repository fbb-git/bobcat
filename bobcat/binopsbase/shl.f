template <class Derived>
struct Shl
{
    Derived &operator<<=(Derived const &rhs) &; 
    Derived &&operator<<=(Derived const &rhs) &&;
};

template <class Derived>
Derived &Shl<Derived>::operator<<=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.shlWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Derived>
Derived &&Shl<Derived>::operator<<=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).shlWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator<<(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.shlWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator<<(Derived &&lhs, Derived const &rhs)
{
    lhs.shlWrap(rhs);
    return std::move(lhs);
}

template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '<', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Shl<Derived>
{};
