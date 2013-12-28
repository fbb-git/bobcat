inline Process &Process::operator()(IOMode mode)
{
    return operator()(mode, d_setProcessType, d_setTimeLimit);
}
