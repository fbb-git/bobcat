    friend Mul<BinopsBase<Derived, ops...>, Derived>;
    friend Div<BinopsBase<Derived, ops...>, Derived>;
    friend Mod<BinopsBase<Derived, ops...>, Derived>;
    friend Add<BinopsBase<Derived, ops...>, Derived>;
    friend Sub<BinopsBase<Derived, ops...>, Derived>;
    friend Shl<BinopsBase<Derived, ops...>, Derived>;
    friend Shr<BinopsBase<Derived, ops...>, Derived>;
    friend And<BinopsBase<Derived, ops...>, Derived>;
    friend  Or<BinopsBase<Derived, ops...>, Derived>;
    friend Xor<BinopsBase<Derived, ops...>, Derived>;

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





