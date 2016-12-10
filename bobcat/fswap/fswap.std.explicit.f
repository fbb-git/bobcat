    // STDSWAP by default, but an explicit swaptype specification for a member
    //
template <typename Type, typename Member, typename ...List>
class FSwap<ModeType<SwapMode::STDSWAP>, Type, FSwapMode<Member>, List...>: 
                                                            private FSwapBase
{
    static void swap(FSwapPOD<Type> &pod, FSwapMode<Member> &&member, 
                                          List ...memberSpecs);
#include "fswap.friends.decl.f"
};

#include "fswap.std.explicit.imp.f"
