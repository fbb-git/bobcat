inline void OFdStreambuf::open(int fd, size_t n)
{
    open(fd, d_mode, n);
}
