inline void Process::setIOMode(IOMode mode)
{
    d_setMode = sanitizeIOMode(mode);
}
