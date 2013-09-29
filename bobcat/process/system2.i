inline void Process::system(iomode mode)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                                USE_SHELL, d_timeLimit);
}
