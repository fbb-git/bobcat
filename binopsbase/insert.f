template <class Derived>
struct Insert
{};

template <class Derived>
std::ostream &operator<<(std::ostream &out, Derived const &rhs)
{
    return rhs.insertWrap(out);
}

template <class Derived, int ...ops>
class BinopsBase0<Derived, 'i', ops...>
:
    public BinopsBase0<Derived, ops...>,
    public Insert<Derived>
{};
