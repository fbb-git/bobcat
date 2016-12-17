    // SWAPMEMBER: Use member.swap() on the member at the head of the list.
    //
template <typename Type, typename Member, typename ...List>
void FSwap<ModeType<SwapMode::SWAPMEMBER>, Type, Member, List...>::
    swap(FSwapPOD<Type> &pod, Member &&member, List ...memberSpecs)
{
    typedef typename std::remove_reference<Member>::type MemberType;

    member.swap(                // use the swap member with the
                                // member in the rhs object
        preRawSwap<MemberType>(pod, std::forward<Member>(member))
    );

    FSwap<ModeType<SwapMode::SWAPMEMBER>, Type, List...>:: // then do the tail
        swap(pod, std::forward<List>(memberSpecs) ...);
}


