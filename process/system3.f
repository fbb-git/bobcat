inline void Process::system(IOMode mode, size_t timeLimit)
{
    start(mode, USE_SHELL, timeLimit, bufSize());
}
