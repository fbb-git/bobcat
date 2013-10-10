template <typename FP>
CmdFinder<FP>::CmdFinder(Entry const *begin, Entry const *end, size_t mode)
:
    CmdFinderBase(mode),
    d_count(0),
    d_begin(begin),
    d_end(end)
{}
