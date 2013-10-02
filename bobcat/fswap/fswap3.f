template <typename Tp>
inline void FSwap::Xch<Tp, 2>::fswap(Tp &lhs, Tp &rhs)
{
    tswap<int16_t>(lhs, rhs);
}
