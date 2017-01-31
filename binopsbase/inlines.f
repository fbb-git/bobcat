template <class Derived, int ...ops>
    inline std::ostream &BinopsBase<Derived, ops...>::insertWrap(
                                                std::ostream &out) const
{
    static_cast<Derived const &>(
        static_cast<Insert<Derived> const &>(*this)
    ).insert(out);
    return out;
}

template <class Derived, int ...ops>
inline std::istream &BinopsBase<Derived, ops...>::extractWrap(
                                                            std::istream &in)
{
    static_cast<Derived &>(
        static_cast<Extract<Derived> const &>(*this)
    ).extract(in);
    return in;
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::addWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Add<Derived> &>(*this)
    ).add(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::mulWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Mul<Derived> &>(*this)
    ).mul(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::divWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Div<Derived> &>(*this)
    ).div(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::modWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Mod<Derived> &>(*this)
    ).mod(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::subWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Sub<Derived> &>(*this)
    ).sub(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::shlWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Shl<Derived> &>(*this)
    ).shl(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::shrWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Shr<Derived> &>(*this)
    ).shr(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::andWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<And<Derived> &>(*this)
    ).and_(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::orWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Or<Derived> &>(*this)
    ).or_(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::xorWrap(Derived const &rhs)
{
    static_cast<Derived &>(
        static_cast<Xor<Derived> &>(*this)
    ).xor_(rhs);
}

