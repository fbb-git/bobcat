inline void OFdStreambuf::close()
{
    cleanup(CLOSE_FD);
}
