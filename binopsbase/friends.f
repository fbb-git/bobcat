    friend Mul<Derived>;
    friend Div<Derived>;
    friend Mod<Derived>;
    friend Add<Derived>;
    friend Sub<Derived>;
    friend Shl<Derived>;
    friend Shr<Derived>;
    friend And<Derived>;
    friend  Or<Derived>;
    friend Xor<Derived>;

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





