inline void Process::start(iomode mode)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                        d_setProcessType, d_setTimeLimit);
}
