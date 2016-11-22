    friend class Mul<BinopsBase<Derived, ops...>, Derived>;
    friend class Div<BinopsBase<Derived, ops...>, Derived>;
    friend class Mod<BinopsBase<Derived, ops...>, Derived>;
    friend class Add<BinopsBase<Derived, ops...>, Derived>;
    friend class Sub<BinopsBase<Derived, ops...>, Derived>;
    friend class Shl<BinopsBase<Derived, ops...>, Derived>;
    friend class Shr<BinopsBase<Derived, ops...>, Derived>;
    friend class And<BinopsBase<Derived, ops...>, Derived>;
    friend class  Or<BinopsBase<Derived, ops...>, Derived>;
    friend class Xor<BinopsBase<Derived, ops...>, Derived>;

    friend Derived operator*<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator*<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator/<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator/<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator%<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator%<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator+<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator+<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator-<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator-<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator<<<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator<<<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator>><Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator>><Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator&<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator&<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator|<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator|<Derived>(Derived &&lhs, Derived const &rhs);

    friend Derived operator^<Derived>(Derived const &lhs, Derived const &rhs);
    friend Derived operator^<Derived>(Derived &&lhs, Derived const &rhs);





