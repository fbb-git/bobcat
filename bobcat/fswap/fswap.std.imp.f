    // STDSWAP: Use std::swap on the member at the head of the list.
    //
template <typename Type, typename Member, typename ...List>
void FSwap<ModeType<SwapMode::STDSWAP>, Type, Member, List...>::
    swap(FSwapPOD<Type> &pod, Member &&member, List ...memberSpecs)
{
    typedef typename std::remove_reference<Member>::type MemberType;

    std::swap(member,                   // std swap `member' and the member
              preRawSwap<MemberType>(   // in the rhs object
                  pod, std::forward<Member>(member)
              )
    );

                                        // then do the tail...
    FSwap<ModeType<SwapMode::STDSWAP>, Type, List...>::   
        swap(pod, std::forward<List>(memberSpecs) ...);
}


