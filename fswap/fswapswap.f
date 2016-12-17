template <typename Type>            // how to swap this type?
class FSwapSwap
{
    Type &d_member;

    public:
        typedef Type type;

        FSwapSwap(Type &member);
        Type &member();
};

FSwapSwap<
#include "fswapswapimp.f"

