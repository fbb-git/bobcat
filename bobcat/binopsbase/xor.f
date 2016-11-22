template <class Binops, class Derived>
struct Xor
{
    Derived &operator^=(Derived const &rhs) &; 
    Derived &&operator^=(Derived const &rhs) &&;
};

template <class Binops, class Derived>
Derived &Xor<Binops, Derived>::operator^=(Derived const &rhs) &
{
    Derived tmp{static_cast<Derived &>(*this)};
    tmp.xorWrap(rhs);
    static_cast<Derived &>(*this).swap(tmp);
    return static_cast<Derived &>(*this);
}

template <class Binops, class Derived>
Derived &&Xor<Binops, Derived>::operator^=(Derived const &rhs) &&
{
    static_cast<Derived &>(*this).xorWrap(rhs);
    return std::move(static_cast<Derived &>(*this));
}

template <class Derived>
Derived operator^(Derived const &lhs, Derived const &rhs)
{
    Derived ret{lhs};
    ret.xorWrap(rhs);
    return ret;
}

template <class Derived>
Derived operator^(Derived &&lhs, Derived const &rhs)
{
    lhs.xorWrap(rhs);
    return std::move(lhs);
}

template <class Binops, class Derived, int ...ops>
class BinopsBase0<Binops, Derived, '^', ops...>
:
    public BinopsBase0<Binops, Derived, ops...>,
    public Xor<Binops, Derived>
{};
