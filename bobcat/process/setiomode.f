inline void Process::setIOMode(iomode mode)
{
    d_setMode = sanitizeIOMode(mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC));
}
