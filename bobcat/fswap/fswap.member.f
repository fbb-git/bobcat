    // SWAPMEMBER by default: Use member.swap at the head of the list.
    //
template <typename Type, typename Member, typename ...List>
class FSwap<ModeType<SwapMode::SWAPMEMBER>, Type, Member, List...>: private 
                                                                    FSwapBase
{
    static void swap(FSwapPOD<Type> &pod, Member &&member, 
                                          List ...memberSpecs);
#include "fswap.friends.decl.f"
};

#include "fswap.member.imp.f"
