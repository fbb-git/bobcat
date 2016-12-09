
    // The full fswap function template, requiring an explicit first member 
    // address
    //
template <SwapMode::Enum mode,
          typename First, typename Type, typename ...MemberList>
void fswap(First *firstAddr, Type &lhs, Type &rhs, MemberList &&...swapList)
{
    char buffer[sizeof(Type)];

    FSwapPOD<Type> pod{
        PODfactory(
            buffer, FSwapBase::addr(firstAddr), lhs, rhs
        )
    };

    FSwap<ModeType<mode>, Type, MemberList ...>::
        swap(pod, std::forward<MemberList>(swapList) ...);
}

