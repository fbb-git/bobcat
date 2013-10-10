template <typename FP>
inline CmdFinder<FP> &CmdFinder<FP>::operator=(CmdFinder &&tmp)
{
    FBB::fswap(*this, tmp);
    return *this;
}
