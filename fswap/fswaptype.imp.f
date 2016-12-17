
template <typename Type> 
FSwapMode<Type>::FSwapMode(SwapMode::Enum mode, Type &member)
:
    d_mode(mode),
    d_member(member)
{}

template <typename Type> 
inline SwapMode::Enum FSwapMode<Type>::mode() const
{
    return d_mode;
}

template <typename Type> 
inline Type &FSwapMode<Type>::member() const
{
    return d_member;
}

template <typename Type>            
inline FSwapMode<Type> stdswap(Type &member)
{
    return typename FSwapMode<Type>::FSwapMode(SwapMode::STDSWAP, member);
}


template <typename Type>            
inline FSwapMode<Type> swapmember(Type &member)
{
    return typename FSwapMode<Type>::FSwapMode(SwapMode::SWAPMEMBER, member);
}
