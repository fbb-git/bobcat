template <class Derived>
struct Extract
{};

template <class Derived>
std::istream &operator>>(std::istream &in, Derived &rhs)
{
    return rhs.extractWrap(in);
}

template <class Derived, int ...ops>
class BinopsBase0<Derived, 'e', ops...>
:
    public BinopsBase0<Derived, ops...>,
    public Extract<Derived>
{};
