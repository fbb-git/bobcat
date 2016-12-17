    // traditional fswap operation
    //
template <typename Type>
void fswap(Type &lhs, Type &rhs)
{
    char buffer[sizeof(Type)];

    FSwapPOD<Type> pod{
        PODfactory(buffer, FSwapBase::addr(lhs), lhs, rhs)};

    FSwapBase::rawswap(pod, FSwapBase::addr(&rhs), sizeof(Type));
}
