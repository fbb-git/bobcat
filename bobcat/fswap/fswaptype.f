template <typename Type>            
class FSwapMode
{
    SwapMode::Enum d_mode;
    Type &d_member;

    public:
        typedef Type MemberType;

        FSwapMode(SwapMode::Enum mode, Type &member);
        SwapMode::Enum mode() const;
        Type &member() const;
};

    // FSwapMode constructing functions:

    // for std::swap
    //
template <typename Type>            
inline FSwapMode<Type> stdswap(Type &member);

    // for .swap() members
    //
template <typename Type>            
inline FSwapMode<Type> swapmember(Type &member);

#include "fswaptype.imp.f"

