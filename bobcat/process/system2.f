inline void Process::system(IOMode mode)
{
    start(mode, USE_SHELL, d_timeLimit, bufSize());
}
