    // SWAPMEMBER by default, but an explicit swaptype specification for 
    // the member at the head of the list.
    //
template <typename Type, typename Member, typename ...List>
class FSwap<ModeType<SwapMode::SWAPMEMBER>, 
            Type, FSwapMode<Member>, List...>: private FSwapBase
{
    static void swap(FSwapPOD<Type> &pod, FSwapMode<Member> &&member, 
                                          List ...memberSpecs);

    #include "fswap.friends.decl.f"
};

#include "fswap.member.explicit.imp.f"
