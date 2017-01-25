template <class Derived>
struct Div
{
    Derived &operator/=(Derived const &rhs) &; 
    Derived &&operator/=(Derived const &rhs) &&;
};

template <class Derived>
Derived &Div<Derived>::operator/=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.divWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Derived>
Derived &&Div<Derived>::operator/=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).divWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator/(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.divWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator/(Derived &&lhs, Derived const &rhs)
{
    lhs.divWrap(rhs);
    return std::move(lhs);
}

template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '/', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Div<Derived>
{};
