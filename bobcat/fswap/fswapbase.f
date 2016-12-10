class FSwapBase
{
#include "fswapfun.friends.f"

    protected:
        template <typename Type>                // swap using memcpy
        static void rawswap(FSwapPOD<Type> &pod, char *two, int size);

        template <typename Type>    
        static constexpr char *addr(Type &);    // does reinterpret_cast 

        template <typename Type>    
        static constexpr char *addr(Type *);    // does reinterpret_cast 
    
                                                // use specified swap method
        template <typename Type, typename FSwapMode>
        static void explicitSwap(FSwapPOD<Type> &pod, FSwapMode &&member);
    
                                                // actions before using a
                                                // specific swap method
        template <typename ReturnType, typename Type, typename Member>
        static ReturnType &preRawSwap(FSwapPOD<Type> &pod, Member &&member);
};

#include "fswapbase.imp.f"
