inline Process &Process::operator()(iomode mode, ProcessType type)
{
    return operator()(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                                    type, d_setTimeLimit);
}
