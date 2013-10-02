template <typename FP>
bool CmdFinder<FP>::MatchKey::operator()(CmdFinder::Entry const &entry)
{
    if (!d_cmdFinder->match(entry.first))
        return false;

    *d_fp = entry.second;
    return true;
}
