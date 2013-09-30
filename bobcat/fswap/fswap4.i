template <typename Tp>
inline void FSwap::Xch<Tp, 4>::fswap(Tp &lhs, Tp &rhs)
{
    tswap<int32_t>(lhs, rhs);
}
