inline void Process::start(IOMode mode, ProcessType type)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), type, d_setTimeLimit);
}
