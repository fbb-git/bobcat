inline void Process::system(iomode mode, size_t timeLimit)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), USE_SHELL, timeLimit);
}
