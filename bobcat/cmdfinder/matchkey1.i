template <typename FP>
CmdFinder<FP>::MatchKey::MatchKey(FunctionPtr *fp, CmdFinder<FP> *cmdFinder)
:
    d_fp(fp),
    d_cmdFinder(cmdFinder)
{}
