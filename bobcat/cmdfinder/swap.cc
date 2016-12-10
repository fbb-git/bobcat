#include "cmdfinder.ih"

template <typename FP>
void CmdFinder<FP>::swap(CmdFinder<FP> &rhs)
{
    CmdFinderBase::swap(rhs);

    fswap(&d_count, *this, rhs);
}
