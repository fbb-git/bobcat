inline void Process::system(IOMode mode)
{
    start(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC), 
                                                USE_SHELL, d_timeLimit);
}
