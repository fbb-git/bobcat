inline Process &Process::operator()(iomode mode)
{
    return operator()(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                            d_setProcessType, d_setTimeLimit);
}
