    // Raw memory swapping of a block of size bytes
    //
template <typename Type>
void FSwapBase::rawswap(FSwapPOD<Type> &pod, char *two, int size)
{
    memcpy(pod.d_buffer, pod.d_from, size);  
    memcpy(pod.d_from, two,  size); 
    memcpy(two, pod.d_buffer, size);
}

    // shortcuts for reinterpret_casts
    //
template <typename Type>
constexpr char *FSwapBase::addr(Type &type)
{
    return reinterpret_cast<char *>(&type);
}

template <typename Type>
constexpr char *FSwapBase::addr(Type *type)
{
    return reinterpret_cast<char *>(type);  
}

    // use specified swap method
    //
template <typename Type, typename FSwapMode>
void FSwapBase::explicitSwap(FSwapPOD<Type> &pod, FSwapMode &&member)
{
    typedef typename FSwapMode::MemberType MemberType;

    MemberType &rhsSwap =     // stdSwap's address in the rhs object
            *reinterpret_cast<MemberType *>
            (
                addr(member.member()) - addr(pod.d_lhs) // shift wrt lhs, and
                +                                       // add to
                addr(pod.d_rhs)                         // &rhs
            );

    int const shift = pod.d_from - addr(pod.d_lhs); // #bytes from lhs to from

        // size: #bytes to rawswap
        // size == 0  happens if the last data member uses std::swap and
        // also if two subsequent data members usestd::swap
    int const size = addr(member.member()) - pod.d_from;
    if (size > 0)
        rawswap(pod, addr(pod.d_rhs) + shift, size);
    else if (size < 0)
        throw std::runtime_error(
            "fswap: members must be specified in order of declaration");

    if (member.mode() == SwapMode::STDSWAP)
        std::swap(member.member(), rhsSwap); // MemberTypes do std::swap
    else
        member.member().swap(rhsSwap); // otherwise: use a swap member

    pod.d_from = addr(member.member()) + sizeof(MemberType);
}

    // raw swapping up to a specified member
    //
template <typename ReturnType, typename Type, typename Member>
ReturnType &FSwapBase::preRawSwap(FSwapPOD<Type> &pod, Member &&member)
{
    ReturnType *ret = 

            reinterpret_cast<ReturnType *>
            (
                addr(&member) - addr(pod.d_lhs)     // shift wrt lhs, and
                +                                   // add to
                addr(pod.d_rhs)                     // &rhs
            );

    int const shift = pod.d_from - addr(pod.d_lhs); // #bytes from lhs to from

        // size: #bytes to rawswap
        // size == 0  happens if the last data member uses std::swap and
        // also if two subsequent data members usestd::swap
    int const size = addr(&member) - pod.d_from;
    if (size > 0)
        rawswap(pod, addr(pod.d_rhs) + shift, size);
    else if (size < 0)
        throw std::runtime_error(
            "fswap: members must be specified in order of declaration");


    pod.d_from = addr(&member) + sizeof(ReturnType);

    return *ret;
}

