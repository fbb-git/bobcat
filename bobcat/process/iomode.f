inline Process::iomode Process::ioMode() const
{
    return d_mode & ~(IN_PIPE | OUT_PIPE | CLOSE_ON_EXEC);
}
