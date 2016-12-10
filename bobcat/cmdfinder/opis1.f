template <typename FP>
inline CmdFinder<FP> &CmdFinder<FP>::operator=(CmdFinder &&tmp)
{
    swap(tmp);
    return *this;
}
