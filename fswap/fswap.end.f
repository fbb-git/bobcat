    // End-specialization: nothing more to swap using swap functions
    // but rawswap anything that's left
    //
template <typename Enum, typename Type>
class FSwap<Enum, Type>: private FSwapBase
{
    static void swap(FSwapPOD<Type> &pod);

#include "fswap.friends.decl.f"
};

#include "fswap.end.imp.f"
