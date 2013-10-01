inline void Process::start(iomode mode, ProcessType type)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), type, d_setTimeLimit);
}
