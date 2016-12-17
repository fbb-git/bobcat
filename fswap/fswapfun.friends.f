        // fswap1.f
        //
    template <SwapMode::Enum mode, typename First, typename Tp, 
              typename ...Lst>
    friend void fswap(First *addr, Tp &lhs, Tp &rhs, Lst &&...list);

        // fswap2.f
        //
    template <SwapMode::Enum mode, typename Tp, typename ...Lst>
    friend void fswap(Tp &lhs, Tp &rhs, Lst &&...list);

        // fswap3.f
        //
    template <typename Tp>
    friend void fswap(Tp &lhs, Tp &rhs);

