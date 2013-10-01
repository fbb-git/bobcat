template <typename Tp, size_t size>
void FSwap::Xch<Tp, size>::fswap(Tp &lhs, Tp &rhs)
{
    char buffer[size];
    memcpy(buffer,  &lhs,   size);
    memcpy(&lhs,    &rhs,   size);
    memcpy(&rhs,    buffer, size);
}
