template <typename Type>
class FSwapPOD
{
    friend struct FSwapBase;

    char *d_buffer;
    char *d_from;
    Type &d_lhs;
    Type &d_rhs;

    FSwapPOD(char *buffer, char *from, Type &lhs, Type &rhs);

        // FSwapPOD constructing function
        //
    template <typename Tp>          
    friend FSwapPOD<Tp> PODfactory(char *buffer, char *from, 
                                   Tp &lhs, Tp &rhs);

    template <typename Mode, typename Tp, typename ...SwapModes>
    friend struct FSwap;
};

#include "fswappod.imp.f"

