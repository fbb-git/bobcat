    // SWAPMEMBER, but an explicit specification for the member at the head
    // of the list.
    //
template <typename Type, typename Member, typename ...List>
void FSwap<ModeType<SwapMode::SWAPMEMBER>, Type, FSwapMode<Member>, List...>::
    swap(FSwapPOD<Type> &pod, FSwapMode<Member> &&member, List ...memberSpecs)
{
    explicitSwap(pod, std::forward<FSwapMode<Member>>(member));

    FSwap<ModeType<SwapMode::SWAPMEMBER>, Type, List...>::   // do the tail
        swap(pod, std::forward<List>(memberSpecs) ...);
}
