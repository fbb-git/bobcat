template <class Derived>
struct Mod
{
    Derived &operator%=(Derived const &rhs) &; 
    Derived &&operator%=(Derived const &rhs) &&;
};

template <class Derived>
Derived &Mod<Derived>::operator%=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.modWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Derived>
Derived &&Mod<Derived>::operator%=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).modWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator%(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.modWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator%(Derived &&lhs, Derived const &rhs)
{
    lhs.modWrap(rhs);
    return std::move(lhs);
}

template <class Derived, int ...ops>
class BinopsBase0<Derived, '%', ops...>
:
    public BinopsBase0<Derived, ops...>,
    public Mod<Derived>
{};
