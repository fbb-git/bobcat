template <class Derived>
struct Shr
{
    Derived &operator>>=(Derived const &rhs) &; 
    Derived &&operator>>=(Derived const &rhs) &&;
};

template <class Derived>
Derived &Shr<Derived>::operator>>=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.shrWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Derived>
Derived &&Shr<Derived>::operator>>=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).shrWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator>>(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.shrWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator>>(Derived &&lhs, Derived const &rhs)
{
    lhs.shrWrap(rhs);
    return std::move(lhs);
}

template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '>', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Shr<Derived>
{};
