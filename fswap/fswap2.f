    // the shorter overloaded version, calling fswap1.f with 
    // firstAddr = &lhs, thus not using any shift to the address of the
    // first data member
    //
template <SwapMode::Enum mode,
          typename Type, typename ...MemberList>
inline void fswap(Type &lhs, Type &rhs, MemberList &&...swapList)
{
    fswap<mode>(FSwapBase::addr(lhs), 
        lhs, rhs, std::forward<MemberList>(swapList) ...);
}
