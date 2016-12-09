    // STDSWAP by default: Use std::swap on the member at the head of the
    //  list.
    //
template <typename Type, typename Member, typename ...List>
class  FSwap<ModeType<SwapMode::STDSWAP>, Type, Member, List...>: private 
                                                                FSwapBase
{
    static void swap(FSwapPOD<Type> &pod, Member &&member, 
                                          List ...memberSpecs);
    #include "fswap.friends.decl.f"
};

#include "fswap.std.imp.f"

