template <class Binops, class Derived>
struct Or
{
    Derived &operator|=(Derived const &rhs) &; 
    Derived &&operator|=(Derived const &rhs) &&;
};

template <class Binops, class Derived>
Derived &Or<Binops, Derived>::operator|=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.orWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Binops, class Derived>
Derived &&Or<Binops, Derived>::operator|=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).orWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator|(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.orWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator|(Derived &&lhs, Derived const &rhs)
{
    lhs.orWrap(rhs);
    return std::move(lhs);
}

template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '|', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Or<Binops, Derived>
{};
