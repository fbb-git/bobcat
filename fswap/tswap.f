template <typename SwapType, typename Type>
void FSwap::tswap(Type &lhs, Type &rhs)
{
    static_assert(sizeof(SwapType) == sizeof(Type),
                "BOBCAT DESIGN ERROR: "
                "FSwap::tswap(): sizeof(SwapType) != sizeof(Type)");

    SwapType tmp = *reinterpret_cast<SwapType *>(&lhs);
    *reinterpret_cast<SwapType *>(&lhs) = *reinterpret_cast<SwapType *>(&rhs);
    *reinterpret_cast<SwapType *>(&rhs) = tmp;
}
