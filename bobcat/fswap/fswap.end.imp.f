    // End-specialization: nothing more to swap using swap functions:
    // rawswap anything that's left
    //
template <typename Enum, typename Type>
void FSwap<Enum, Type>::swap(FSwapPOD<Type> &pod)
{
    int const shift = pod.d_from - addr(pod.d_lhs); // 'from' location in lhs
    int const size = sizeof(Type) - shift;          // # bytes beyond 'from'

    rawswap(pod, addr(pod.d_rhs) + shift, size);
}
