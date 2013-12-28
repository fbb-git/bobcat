inline void Process::system(IOMode mode, size_t timeLimit, size_t bufSize)
{
    start(mode, USE_SHELL, timeLimit, bufSize);
}
