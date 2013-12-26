inline Process &Process::operator()(IOMode mode)
{
    return operator()(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                            d_setProcessType, d_setTimeLimit);
}
