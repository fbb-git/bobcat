template <typename Tp>
inline void FSwap::Xch<Tp, 8>::fswap(Tp &lhs, Tp &rhs)
{
    tswap<int64_t>(lhs, rhs);
}
