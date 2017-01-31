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
    friend Insert<Derived>;
    friend Extract<Derived>;

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

    friend std::istream &operator>><Derived>(std::istream &in, Derived &rhs);
    friend std::ostream &operator<<<Derived>(std::ostream &out, 
                                                        Derived const &rhs);




