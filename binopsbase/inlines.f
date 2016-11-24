    
template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::addWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).add(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::mulWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).mul(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::divWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).div(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::modWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).mod(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::subWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).sub(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::shlWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).shl(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::shrWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).shr(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::andWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).and_(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::orWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).or_(rhs);
}

template <class Derived, int ...ops>
inline void BinopsBase<Derived, ops...>::xorWrap(Derived const &rhs)
{
    static_cast<Derived &>(*this).xor_(rhs);
}

