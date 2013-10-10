inline void IFdStreambuf::close()
{
    cleanup(CLOSE_FD);
}
