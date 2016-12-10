    // fswap1.f
    //
template <SwapMode::Enum mode = SwapMode::SWAPMEMBER,
          typename First, typename Type, typename ...MemberList>
void fswap(First *firstAddr, Type &lhs, Type &rhs, MemberList &&...swapList);

    // fswap2.f
template <SwapMode::Enum mode = SwapMode::SWAPMEMBER,
          typename Type, typename ...MemberList>
inline void fswap(Type &lhs, Type &rhs, MemberList &&...swapList);

